class Solution {
    public int minimumDeletions(int[] nums){
        int n = nums.length;
        int min = 0;
        int max = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < nums[min])
                min = i;
            if(nums[i] > nums[max])
                max = i;
        }

        int mx = Math.max(min,max);
        int mn = Math.min(min,max);
        int choice3 = min + 1 + (n - max);
        int choice4 = max + (n - min + 1);
        int sol = mx+1;
        sol = Math.min(sol,n - mn);
        sol = Math.min(sol,choice3);
        sol = Math.min(sol,choice4);
        return sol;
    }
}