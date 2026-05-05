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

    int rec(TreeNode* cur ,int v){
        if(cur == nullptr)
            return v;
        int ans = 0;
        if(!cur->left && !cur-> right)
            ans += rec(cur->left,v*10+cur->val);
        else{
            if(cur->left)
            ans += rec(cur->left,v*10+cur->val);
            if(cur->right)
            ans += rec(cur->right,v*10+cur->val);
        }
        return ans;
    }

    int sumNumbers(TreeNode* root) {
        return rec(root,0);
    }
};