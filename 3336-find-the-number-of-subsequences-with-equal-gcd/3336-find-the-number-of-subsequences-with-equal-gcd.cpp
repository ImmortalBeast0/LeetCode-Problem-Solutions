class Solution {
public:
    int n;
    int const mod = 1e9 + 7;
    int gcd(int x ,int y){
        if(x == 201)
            return y;
        return __gcd(x,y);
    }

    int dp[201][202][202];
    int rec(int i ,int g1 ,int g2 ,vector<int>& nums){
        if(i >= n)
            return g1 == g2;

        if(dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        int ans = 0;
        ans += rec(i+1,g1,g2,nums);
        ans %= mod;
        ans += rec(i+1,gcd(g1,nums[i]),g2,nums);
        ans %= mod;
        ans += rec(i+1,g1,gcd(g2,nums[i]),nums);
        ans %= mod;
    
        return dp[i][g1][g2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,201,201,nums) - 1;
    }
};