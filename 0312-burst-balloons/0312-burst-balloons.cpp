class Solution {
public:
    int n;
    int dp[303][303];
    int rec(int i ,int j ,vector<int>& nums){
        if(j - i < 2)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans = 0;
        for(int k=i+1;k<j;k++){
            int coins = nums[i] * nums[k] * nums[j]; 
            ans = max(ans,rec(i,k,nums) + rec(k,j,nums) + coins);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums){
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,nums);
    }
};