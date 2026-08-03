class Solution {
    int n;
    public record Score(int a ,int b){};
    Score dp[][];

    Score getLargest(int p1 ,int p2 ,int p3 ,int sc1 ,int sc2 ,int sc3){
        Score sc;
        if(p1 >= p2 && p1 >= p3){
            sc = new Score(p1,sc1);
            if(p1 == p2 && sc.b > sc2)
                sc = new Score(p1,sc2);
            if(p1 == p3 && sc.b > sc3)
                sc = new Score(p1,sc3);
        }else if(p2 >= p3){
            sc = new Score(p2,sc2);
            if(p2 == p3 && sc.b > sc3) 
                sc = new Score(p2,sc3);
        }else
            sc = new Score(p3,sc3);

        return sc;
    }

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

            ans = getLargest(pickOne,pickTwo,pickThree,one.b(),two.b(),three.b());
        }else{
            int pickOne = nums[i] + one.b();
            int pickTwo,pickThree;
            pickTwo = pickThree = -(int)1e9;
            if(i+1 < n)
                pickTwo = nums[i] + nums[i+1] + two.b();
            if(i + 2 < n)
                pickThree = nums[i] + nums[i+1] + nums[i + 2] + three.b();

           ans = getLargest(pickOne,pickTwo,pickThree,one.a(),two.a(),three.a());
           ans = new Score(ans.b,ans.a);
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