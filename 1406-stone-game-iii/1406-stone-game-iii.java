class Solution {
    int n;
    public record Score(int a ,int b){};
    Score dp[][];
    Score rec(int i ,boolean turn ,int[] nums){

        if(i >= n)
            return new Score(0,0);
        if(dp[i][turn ? 1 : 0] != null)
            return dp[i][turn ? 1 : 0];

        Score one = rec(i+1,!turn,nums);
        Score two = rec(i+2,!turn,nums);
        Score three = rec(i+3,!turn,nums);
        Score ans;
        if(turn){
            int pickOne = nums[i] + one.a();
            int pickTwo,pickThree;
            pickTwo = pickThree = -(int)1e9;
            if(i+1 < n)
                pickTwo = nums[i] + nums[i+1] + two.a();
            if(i + 2 < n)
                pickThree = nums[i] + nums[i+1] + nums[i + 2] + three.a();

            if(pickOne >= pickTwo && pickOne >= pickThree)
                ans = new Score(pickOne,one.b());
            else if(pickTwo >= pickThree)
                ans = new Score(pickTwo,two.b());
            else
                ans = new Score(pickThree,three.b());
        }else{
            int pickOne = nums[i] + one.b();
            int pickTwo,pickThree;
            pickTwo = pickThree = -(int)1e9;
            if(i+1 < n)
                pickTwo = nums[i] + nums[i+1] + two.b();
            if(i + 2 < n)
                pickThree = nums[i] + nums[i+1] + nums[i + 2] + three.b();

            if(pickOne >= pickTwo && pickOne >= pickThree)
                ans = new Score(one.a(),pickOne);
            else if(pickTwo >= pickThree)
                ans = new Score(two.a(),pickTwo);
            else
                ans = new Score(three.a(),pickThree);
        }

        return dp[i][turn ? 1 : 0] = ans;
    }

    public String stoneGameIII(int[] stoneValue){
        n = stoneValue.length;
        dp = new Score[n+1][2];
        Score sc = rec(0,true,stoneValue);
        if(sc.a > sc.b)
            return "Alice";
        else if(sc.a < sc.b)
            return "Bob";
        else
            return "Tie";
    }
}