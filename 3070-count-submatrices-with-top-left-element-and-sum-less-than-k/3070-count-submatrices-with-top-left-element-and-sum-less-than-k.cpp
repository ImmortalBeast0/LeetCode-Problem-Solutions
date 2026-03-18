#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<vector<int>> ps;

    int prefixsum(int n,int m,vector<vector<int>> &nums ,int k){

        ps.resize(n+1,vector<int>(m+1,0));
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                ps[i][j] = ps[i-1][j] + ps[i][j-1] + nums[i-1][j-1] - ps[i-1][j-1];
                ans += (ps[i][j] <= k);
            }
        }

        return ans;
    }

    int countSubmatrices(vector<vector<int>>& grid, int k){
        int n = grid.size();
        int m = grid[0].size();

        return prefixsum(n,m,grid,k);
    }
};
