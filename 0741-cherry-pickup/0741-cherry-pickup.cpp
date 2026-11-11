class Solution {
public:
    int n;
    int dp[55][55][55][55];
    int rec(int i1 ,int j1 ,int i2 ,int j2 ,vector<vector<int>>& g){

        if(i1 == n-1 && j1 == n-1 && i2 == n-1 && j1 == n-1)
            return g[i1][j1];

        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n)
            return -1e9;

        if(g[i1][j1] == -1 || g[i2][j2] == -1)
            return -1e9;

        if(dp[i1][j1][i2][j2] != -1)
            return dp[i1][j1][i2][j2];

        int get = 0;
        if(i1 == i2 && j1 == j2)
            get += g[i1][j1];   
        else
            get += g[i1][j1] + g[i2][j2];

        int ans = -1e9;
        ans = max(ans,rec(i1+1,j1,i2+1,j2,g) + get);
        ans = max(ans,rec(i1+1,j1,i2,j2+1,g) + get);
        ans = max(ans,rec(i1,j1+1,i2+1,j2,g) + get);
        ans = max(ans,rec(i1,j1+1,i2,j2+1,g) + get);
        return dp[i1][j1][i2][j2] = ans;
    }   

    int cherryPickup(vector<vector<int>>& g){
        n = g[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,0,0,0,g);
        if(ans < 0)
            ans = 0;
        return ans;
    }
};