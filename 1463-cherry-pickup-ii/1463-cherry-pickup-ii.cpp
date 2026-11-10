class Solution {
public:
    int m ,n;
    int dp[77][77][77];
    int rec(int i ,int j1 ,int j2 ,vector<vector<int>>& g){

        if(i >= m)
            return 0;
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
            return -1e9;
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int ans = -1e9;
        int tot = 0;
        if(j1 == j2)
            tot += g[i][j1];
        else
            tot += g[i][j1] + g[i][j2];

        for(int t=-1;t<2;t++){
            ans = max(ans,rec(i+1,j1-1,j2+t,g));
            ans = max(ans,rec(i+1,j1,j2+t,g));
            ans = max(ans,rec(i+1,j1+1,j2+t,g));
        }

        return dp[i][j1][j2] = ans + tot;
    }

    int cherryPickup(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n-1,g);
    }
};