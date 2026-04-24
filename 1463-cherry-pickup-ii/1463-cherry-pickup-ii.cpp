#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
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

class Solution {
public:
    int m ,n;

    int dp[70][70][70];

    int rec(int i ,int j ,int k ,vii& g){
        if (i >= m)
            return 0;

        if (j >= n || j < 0 || k >= n || k < 0)
            return -1e9;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int ans = -1e9;
        int v1 = g[i][j], v2 = g[i][k];
        if (j == k)
            v2 = 0;

        ans = max(ans, rec(i + 1, j, k, g) + v1 + v2);
        ans = max(ans, rec(i + 1, j, k + 1, g) + v1 + v2);
        ans = max(ans, rec(i + 1, j, k - 1, g) + v1 + v2);
        ans = max(ans, rec(i + 1, j + 1, k, g) + v1 + v2);
        ans = max(ans, rec(i + 1, j + 1, k + 1, g) + v1 + v2);
        ans = max(ans, rec(i + 1, j + 1, k - 1, g) + v1 + v2);
        ans = max(ans, rec(i + 1, j - 1, k, g) + v1 + v2);
        ans = max(ans, rec(i + 1, j - 1, k + 1, g) + v1 + v2);
        ans = max(ans, rec(i + 1, j - 1, k - 1, g) + v1 + v2);

        return dp[i][j][k] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n-1,grid);
    }
};