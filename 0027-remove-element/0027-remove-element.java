class Solution {
    public int removeElement(int[] nums, int val) {
        int n = nums.length;
        int i = 0 ,j = n - 1 ,cnt = 0;
        while(i <= j){
            while(i <= j && nums[i] != val)
                i += 1;
            while(i <= j && nums[j] == val){
                cnt += 1;
                j -= 1;
            }
            if(i <= j){
                cnt += 1;
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i += 1;
                j -= 1;
            }
        }

        return n - cnt;
    }
}