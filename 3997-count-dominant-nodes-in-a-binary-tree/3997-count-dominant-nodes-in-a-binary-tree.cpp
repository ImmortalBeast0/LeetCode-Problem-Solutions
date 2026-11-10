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

    int cnt = 0;

    int rec(TreeNode* root){
        if(root == nullptr)
            return -1;

        int cur = root->val;
        cur = max(cur,rec(root->left));
        cur = max(cur,rec(root->right));

        cnt += (cur == root->val);
        return cur;
    }

    int countDominantNodes(TreeNode* root) {
        rec(root);
        return cnt;
    }
};