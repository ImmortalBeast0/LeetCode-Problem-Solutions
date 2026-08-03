class Solution {
    public record Score(int a ,int b){};
    Score [][]dp;
    Score rec(int i ,int j ,boolean turn ,int[] nums){
        if(i > j)
            return new Score(0,0);

        if(dp[i][j] != null)
            return dp[i][j];

        Score left = rec(i+1,j,!turn,nums);
        Score right = rec(i,j-1,!turn,nums);
        Score ans;
        if(turn){
            int pickLeft = nums[i] + left.a();
            int pickRight = nums[j] + right.a();

            if(pickLeft >= pickRight)
                ans = new Score(pickLeft,left.b());
            else
                ans = new Score(pickRight,right.b());
        }else{
            int pickLeft = nums[i] + left.b();
            int pickRight = nums[j] + right.b();

            if(pickLeft >= pickRight)
                ans = new Score(left.a(),pickLeft);
            else
                ans = new Score(right.a(),pickRight);
        }

        return dp[i][j] = ans;
    }

    public boolean predictTheWinner(int[] nums) {
        dp = new Score[nums.length][nums.length];
        Score sc = rec(0,nums.length-1,true,nums);
        return sc.a >= sc.b;
    }
}