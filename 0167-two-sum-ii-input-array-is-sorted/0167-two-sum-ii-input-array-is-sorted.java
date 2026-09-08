class Solution {
    public int[] twoSum(int[] nums, int t) {
        int n = nums.length;
        int i  = 0 ,j = n - 1;
        while(i < j){
            if(nums[i] + nums[j] == t)
                return new int[]{i+1,j+1};
            if(nums[i] + nums[j] < t)
                i += 1;
            else
                j -= 1;
        }

        return new int[]{-1,-1};
    }
}