class Solution {
    public boolean uniformArray(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int odd = 0 ,even = 0;
        for(int i=0;i<n;i++){
            nums[i] = nums[i] % 2;
            odd += nums[i];
            even += nums[i] == 0 ? 1 : 0;
        }

        if(odd == n || even == n)
            return true;

        if(nums[0] % 2 == 0)
            return false;

        return true;
    }
}