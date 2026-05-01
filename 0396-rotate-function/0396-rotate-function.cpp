class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int cur = 0,tot = 0;
       for(int i=0;i<nums.size();i++){
            cur += (i  * nums[i]);
            tot += nums[i];
        }

        int sol = cur;
        for(int i=1;i<nums.size();i++){
            int tmp = cur - (tot - nums[i-1]) + (nums[i-1] * (nums.size() - 1));
            sol = max(sol ,tmp);
            cur = tmp;
        } 

        return sol;
    }
};