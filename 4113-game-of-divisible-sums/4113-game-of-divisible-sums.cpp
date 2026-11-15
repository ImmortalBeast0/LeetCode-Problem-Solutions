class Solution {
public:
    using ll = long long;
    int n;
    
    ll dp[3][(int)1e5+5];
    ll rec(int i ,bool f ,vector<int>& nums){
        if(i >= n)
            return 0;

        if(dp[f][i] != -1)
            return dp[f][i];

        ll ch1 ,ch2 = -1e18;
        if(nums[i] % 3 == 0)
            ch1 = nums[i] - rec(i+1,!f,nums);
        else
            ch1 = nums[i] + rec(i+1,f,nums);
        

        if(i+1 < n)
            if((nums[i] + nums[i+1]) % 3 == 0)
                ch2 = nums[i] + nums[i+1] - (rec(i+2,!f,nums));
            else
                ch2 = nums[i] + nums[i+1] + rec(i+2,f,nums);

        ll ans = max(ch1,ch2);
        return dp[f][i] = ans;
    }

    long long maxDifference(vector<int>& nums){
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,true,nums);
    }
};