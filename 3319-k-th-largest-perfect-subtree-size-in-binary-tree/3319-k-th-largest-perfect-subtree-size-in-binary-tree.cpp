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

    vi pf;
    unordered_map<TreeNode*,int> subsz;
    int dfs(TreeNode* cur){

        // subsz[cur] = 1;
        // if(cur->left == nullptr && cur->right == nullptr){
        //     pf.pb(1);
        //     return 1;
        // }
        
        // if(cur->left == nullptr || cur->right == nullptr){
        //     subsz[cur] += 1;
        //     pf.pb(1);
        //     return 0;
        // }

        if(cur == nullptr)
            return 1;

        subsz[cur] = 1;

        int lt = dfs(cur->left);
        int rt = dfs(cur->right);

        subsz[cur] += subsz[cur->left];
        subsz[cur] += subsz[cur->right];
        if(lt && rt && (subsz[cur->left] == subsz[cur->right])){
            pf.pb(subsz[cur]);
            return 1;
        }
        return 0;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k){
        pf.clear();
        subsz.clear();
        dfs(root);
        sort(all(pf));
        reverse(all(pf));
        if(pf.size() >= k)
            return pf[k-1];
        return -1;
    }
};  