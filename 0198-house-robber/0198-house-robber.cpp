class Solution {
public:
    int n;
    int dp[132];
    int rec(int i ,vector<int>& nums){
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = -1e9;
        ans = max(ans,rec(i+1,nums));
        ans = max(ans,rec(i+2,nums) + nums[i]);

        return dp[i] = ans;
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,nums);
    }
};