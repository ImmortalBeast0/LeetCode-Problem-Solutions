class Solution {
public:
    int minElement(vector<int>& nums) {
        int sol = nums[0];
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            int sum = 0;
            while(x){
                sum += (x % 10);
                x /= 10;
            }
            sol = min(sol,sum);
        }
        return sol;
    }
};