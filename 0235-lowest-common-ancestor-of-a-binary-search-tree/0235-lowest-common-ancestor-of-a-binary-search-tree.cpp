/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* sol = nullptr;
    int pv ,qv;
    bool dfs(TreeNode* cur){
        if(cur == nullptr)
            return false;

        sol = cur;
        if(pv < cur->val && qv < cur->val){
            if(dfs(cur->left))
                return true;
        }else if(pv > cur->val && qv > cur->val){
            if(dfs(cur->right))
                return true;
        }else
            return true;

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        pv = p->val;
        qv = q->val;
        dfs(root);
        return sol;
    }
};