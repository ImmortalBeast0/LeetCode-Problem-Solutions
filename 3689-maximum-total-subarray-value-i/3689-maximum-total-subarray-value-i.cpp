class Solution {
public:
    long long maxTotalValue(vector<int>& nums,int k) {
        long long mx = nums[0];
        long long mn = nums[0];
        for(long long x : nums){
            mx = max(x,mx);
            mn = min(x,mn);
        }

        return k * (mx - mn);
    }
};