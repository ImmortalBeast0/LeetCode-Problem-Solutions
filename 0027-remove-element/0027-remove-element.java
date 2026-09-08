class Solution {
    public int removeElement(int[] nums, int val) {
        int n = nums.length;
        int i = 0 ,j = 0 ,cnt = 0;
        while(j < n){
            if(nums[j] != val){
                cnt += 1;
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i += 1;
                j += 1;
            }else
                j += 1;
        }

        return cnt;
    }
}