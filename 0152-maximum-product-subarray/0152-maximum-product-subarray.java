class Solution {
    public int maxProduct(int[] nums) {
        int sol = nums[0];
        int max = 1 ,min = 1;
        for(int i=0;i<nums.length;i++){
            int t = nums[i] * max;
            max = Math.max(t,min * nums[i]);
            max = Math.max(max,nums[i]);
            min = Math.min(t,min * nums[i]);
            min = Math.min(min,nums[i]);
            sol = Math.max(sol,max);
        }

        return sol;
    }
}