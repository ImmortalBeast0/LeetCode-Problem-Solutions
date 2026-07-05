class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        
        int n = nums.size();

        int mx = 0;
        vector<int> premx(n);
        int sol = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            premx[i] = mx;
            if(i-k >= 0)
                sol = max(sol,nums[i] + premx[i-k]);
        }

        return sol;
    }
};