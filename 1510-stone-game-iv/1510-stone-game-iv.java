class Solution {
    boolean[] dp ,complete;
    boolean rec(int i){
        if(i == 0)
            return false;

        if(complete[i])
            return dp[i];

        for(int j=(int)Math.sqrt(i);i - j*j >= 0 && j!= 0;j--)
            if(!rec(i - j*j)){
                complete[i] = true;
                return dp[i] = true;}

        complete[i] = true;
        return dp[i] = false;
    }


    public boolean winnerSquareGame(int n) {
        dp = new boolean[n+1];
        complete = new boolean[n+1];
       return rec(n);
    }
}