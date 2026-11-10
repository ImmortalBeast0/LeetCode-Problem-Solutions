class Solution {
public:
    int n;
    int dp[(int)1e5 + 5];
    int rec(int i ,vector<int>& costs){
        if(i >= n-1)
            return 0;

        if(dp[i + 1] != -1)
            return dp[i + 1];

        int ans = 1e9;
        if(i+1 < n)
            ans = min(ans,rec(i+1,costs) + costs[i+1] + 1);
        if(i+2 < n)
            ans = min(ans,rec(i+2,costs) + costs[i+2] + 4);
        if(i+3 < n)
            ans = min(ans,rec(i+3,costs) + costs[i+3] + 9);

        return dp[i + 1] = ans;
    }

    int climbStairs(int n_, vector<int>& costs) {
        n = n_;
        memset(dp,-1,sizeof(dp));
        return rec(-1,costs);
    }
};