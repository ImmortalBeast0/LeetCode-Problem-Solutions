#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int m ,n;
    vector<vector<int>> vis;

    int di[4] = {-1,0,1,0} ,dj[4] = {0,1,0,-1};

    void dfs(int i ,int j ,vector<vector<char>>& grid){

        vis[i][j] = 1;
        
        for(int d=0;d<4;d++){
            int ni = i + di[d],nj = j + dj[d];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n)
                if(!vis[ni][nj] && grid[ni][nj] == '1')
                    dfs(ni,nj,grid);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        
        int sol = 0;
        m = grid.size() ,n = grid[0].size();
        vis.resize(m,vector<int> (n,0));
    
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid);
                    sol += 1;
                }
        
        return sol;
    }
};
