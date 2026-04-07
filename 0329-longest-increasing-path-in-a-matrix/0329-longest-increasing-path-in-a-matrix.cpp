#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m , n;
    vector<vector<int>> vis;
    int di[4] = {-1,0,1,0} ,dj[4] = {0,1,0,-1};   

    bool check(int i ,int j){
        return i >= 0 && i < m && j >= 0 && j < n && !vis[i][j];
    }
    
    int dp[202][202];

    int dfs(int i ,int j ,vector<vector<int>>& grid){

        if(dp[i][j] != -1)
            return dp[i][j];

        vis[i][j] = 1;
        bool path = 1;
        int ans = -1e9;
        for(int d=0;d<4;d++){
            int ni = i + di[d] ,nj = j + dj[d];
            if(check(ni,nj) && grid[i][j] < grid[ni][nj])
                ans = max(ans ,1 + dfs(ni,nj,grid)) ,path = 0;
        }

        vis[i][j] = 0;
        if(path)
            return dp[i][j] = 0;
        else
            return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {

        m = mat.size(), n = mat[0].size();
        vis.resize(m,vector<int>(n,0));

        
        int bst = -1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                memset(dp,-1,sizeof(dp));
                bst = max(bst,dfs(i,j,mat));
            }

        return bst + 1;
    }
};
