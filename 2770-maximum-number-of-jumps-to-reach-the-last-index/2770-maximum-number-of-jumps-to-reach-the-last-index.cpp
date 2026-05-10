class Solution {
public:
    int n,tar;
    int dp[(int)1e3+1];
    int rec(int i ,vector<int>& nums){
        if(i == n-1)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = -1e9;
        for(int j=i+1;j<n;j++)
            if(abs(nums[j] - nums[i]) <= tar)
                ans = max(ans,1 + rec(j,nums));

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        tar = target;
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,nums);
        if(ans < 0)
            ans = -1;
        return ans;
    }
};