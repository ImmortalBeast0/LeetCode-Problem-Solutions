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
    TreeNode* createBinaryTree(vector<vector<int>>& desc){
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,int> par;
        for(vector<int> d : desc){
            int id = d[0];
            int childId = d[1];
            bool pos = d[2];
            if(mp.find(id) == mp.end())
                mp[id] = new TreeNode(id);
            if(mp.find(childId) == mp.end())
                mp[childId] = new TreeNode(childId);
            par[childId] = id;
            if(pos)
                mp[id]->left = mp[childId];
            else
                mp[id]->right = mp[childId];
        }

        TreeNode* root = nullptr;
        for(auto [i,x] : mp)
            if(par.find(i) == par.end()){
                root = x;
                break ;
            }

        return root;
    }
};