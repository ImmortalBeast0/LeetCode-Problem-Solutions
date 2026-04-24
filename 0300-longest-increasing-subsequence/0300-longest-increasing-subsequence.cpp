#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int dp[2532];
    int rec(int i ,vector<int>& nums){
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j=0;j<i;j++){
            if(nums[j] < nums[i])
                ans =max(ans ,rec(j,nums) + 1);
        }
        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int bst = 1;
        for(int i=n-1;i>=0;i--)
            bst = max(bst,rec(i,nums));
        return bst;
    }
};

