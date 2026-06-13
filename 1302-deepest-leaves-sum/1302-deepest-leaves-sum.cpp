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
    map<int,vector<int>> mp;
    int mx_d = 0;
    void dfs(TreeNode* u ,int d){
        mx_d = max(mx_d,d);
        mp[d].push_back(u->val);
        if(u->left)
            dfs(u->left,d+1);
        if(u->right)
            dfs(u->right,d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return accumulate(mp[mx_d].begin(),mp[mx_d].end(),0);
    }
};