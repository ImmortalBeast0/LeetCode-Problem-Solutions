#define ll long long
class Solution {
public:
    int n;
    ll k;
    vector<ll> nums;

    ll op(ll x ,bool flag){
        if(flag)
            return x * k;
        return trunc(x / (k * 1.0));
    }

    ll kadane(bool flag){

        vector<ll> dp1(n),dp2(n),dp3(n);
        dp1[0] = nums[0];
        dp2[0] = op(nums[0],flag);
        dp3[0] = dp2[0];
        for(int i=1;i<n;i++){
            ll v = op(nums[i],flag);
            dp1[i] = max(nums[i],dp1[i-1] + nums[i]);
            dp2[i] = max({v ,dp1[i-1]+v,dp2[i-1]+v});
            dp3[i] = max({dp2[i],dp3[i-1]+nums[i],dp2[i-1]+nums[i]});
        }

        ll ans = dp1[0];
        for(int i=0;i<n;i++)
            ans = max({ans,dp1[i],dp2[i],dp3[i]});

        return ans;
    }

    ll maxSubarraySum(vector<int>& nums_, int k_){
        k = k_;
        n = nums_.size();
        for(int x : nums_)  nums.push_back(x);

        return max(kadane(0),kadane(1));
    }
};