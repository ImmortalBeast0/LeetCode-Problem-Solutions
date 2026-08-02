class Solution {
    int dp[][] = new int[20][20];
    int rec(int i ,int j ,int[] nums){
        if(i == j)
            return nums[i];
        if(dp[i][j] != -1)
            return dp[i][j];
        int lt = nums[i] - rec(i+1,j,nums);
        int rt = nums[j] - rec(i,j-1,nums);
        return dp[i][j] = Math.max(lt,rt);
    }
    public boolean predictTheWinner(int[] nums){
        for(int i=0;i<20;i++)
        Arrays.fill(dp[i],-1);
        return rec(0,nums.length-1,nums) >= 0;
    }
}