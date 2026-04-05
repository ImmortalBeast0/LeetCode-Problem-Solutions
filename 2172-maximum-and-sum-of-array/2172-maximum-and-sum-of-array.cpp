#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod ((int)1e9+7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>
#define pb push_back
#define bp pop_back
#define F first
#define S second
#define all(x) x.begin(),x.end()

class Solution {
public:

    int n ,slots;
    int dp[4][10][1 << 19];
    int rec(int curSlot ,int taken ,int mask ,vector<int>& nums){
        if(curSlot >= slots)
            return 0;

        if(dp[taken][curSlot][mask] != -1)
            return dp[taken][curSlot][mask]; 

        int ans = -1e9;
        ans = max(ans,rec(curSlot+1,0,mask,nums));
        for(int i=0;i<n;i++){
            if((mask >> i) & 1) continue;
            if(taken + 1 <= 2)
                ans = max(ans,rec(curSlot,taken+1,mask | (1 << i),nums) + ((curSlot+1) & nums[i]));
        }

        return dp[taken][curSlot][mask] = ans;
    }

    int maximumANDSum(vector<int>& nums, int numSlots_) {
        slots = numSlots_;
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,nums);
    }
};