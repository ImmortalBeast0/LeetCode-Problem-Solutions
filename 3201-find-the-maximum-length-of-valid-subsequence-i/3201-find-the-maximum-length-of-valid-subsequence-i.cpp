class Solution {
public:
    int n;
    vector<int> nums;
    int dp[(int)(2*1e5+5)][4];
    int rec(int i ,int last){
        if(i == n)
            return 0;

        if(dp[i][last+1] != -1)
            return dp[i][last+1];

        int ans = -1e9;
        if(last == -1 || nums[i] != last)
            ans = max(ans,1 + rec(i+1,nums[i]));
        
        ans = max(ans ,rec(i+1,last));

        return dp[i][last+1] = ans;
    }

    int maximumLength(vector<int>& arr) {
        n = arr.size();
        int ones = 0;
        for(int x : arr){
            ones += x % 2;
            nums.push_back(x % 2);
        }
        
        int ans = max(ones,n - ones);
        memset(dp,-1,sizeof(dp));
        return max(ans,rec(0,-1));
    }
};