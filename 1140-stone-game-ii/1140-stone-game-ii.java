class Solution {
    int dp[][][];
    int rec(int i ,int m ,boolean alice ,int[] piles){

        if(i >= piles.length)
            return 0;

        if(dp[i][m][alice ? 0 : 1] > 0)
            return dp[i][m][alice ? 0 : 1];

        int ans = alice ? 0 : (int)1e9;
        int total = 0;
        for(int x=1;x<=2*m;x++){
            if(i + x > piles.length)
                break;
            total += piles[i + x - 1];
            if(alice)
                ans = Math.max(ans,rec(i+x,Math.max(m,x),!alice,piles) + total);
            else
                ans = Math.min(ans,rec(i+x,Math.max(m,x),!alice,piles));
        }

        return dp[i][m][alice ? 0 : 1] = ans;
    }

    public int stoneGameII(int[] piles) {
        dp = new int[piles.length][piles.length+1][2];
        return rec(0,1,true,piles);
    }
}