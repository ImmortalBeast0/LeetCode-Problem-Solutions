#include<bits/stdc++.h>
using namespace std;

#define mod ((ll)1e9+7)
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:

    int sol = -1e9;
    vi dfs(TreeNode* cur){
        if(cur == nullptr){
            return {1,0,(int)-1e9,(int)1e9};
        }

        vi lt = dfs(cur->left);
        vi rt = dfs(cur->right);

        if(lt[0] && rt[0]){
            bool pf = true;
            if(cur->left != nullptr && cur->val <= lt[2])
                pf = false;
            if(cur->right != nullptr && cur->val >= rt[3])
                pf = false;

            int summ = lt[1]+ rt[1]+ cur->val;
            if(pf){
                sol = max(sol,summ);
                return {pf,summ,max(cur->val,rt[2]),min(cur->val,lt[3])};
            }
        }

        return {0,0};
    }

    int maxSumBST(TreeNode* root) {
        sol = 0;
        dfs(root);
        return sol;
    }
};