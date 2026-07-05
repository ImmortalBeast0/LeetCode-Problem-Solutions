class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int mx = 0;
        int sol = 0;
        for(int i=0,j=k;j<n;j++,i++){
            mx = max(mx,nums[i]);
            sol = max(sol,nums[j] + mx); 
        }

        return sol;
    }
};