class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i : nums)
            mx |= i;

        int sol = 0;
        for(int i = 0 ;i < (1 << n) ;i++){
            int cur = 0;
            for(int j = 0 ; j < n ;j++ ){
                if((i >> j) & 1)
                    cur |= nums[j];
            }
            sol += (mx == cur);
        }
        
        return sol;
    }
};