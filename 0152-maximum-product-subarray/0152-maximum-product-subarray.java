class Solution {
    public int maxProduct(int[] nums) {
        int sol = nums[0];
        int max = 1 ,min = 1;
        for(int i=0;i<nums.length;i++){
            sol = Math.max(sol,nums[i]);
            if(nums[i] == 0){
                max = min = 1;
                continue;
            }
            if(nums[i] < 0){
                max += min;
                min = max - min;
                max = max - min;
            }
            max = Math.max(nums[i],max * nums[i]);
            min = Math.min(nums[i],min * nums[i]);
            sol = Math.max(sol,max);
        }

        return sol;
    }
}