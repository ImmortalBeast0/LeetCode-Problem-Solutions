/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    

    vector<int> largestValues(TreeNode* root) {
        vector<int> sols;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int mx = INT_MIN;
            bool f = false;
            while(sz--){
                if(q.front() == nullptr){
                    q.pop();
                    continue;
                }
                f = true;
                mx = max(mx,q.front()->val);
                q.push(q.front()->left);
                q.push(q.front()->right);
                q.pop();
            }
            if(f)
                sols.push_back(mx);
        }

        return sols;
    }
};