class Solution {
    int[][] dp = new int[1001][1001];
    boolean[][] flags = new boolean[1001][1001];
    int rec(int i ,int j ,String s ,String t){
        if(j == t.length())
            return 1;

        if(i == s.length())
            return 0;

        if(flags[i][j])
            return dp[i][j];

        int ans = 0;
        if(s.charAt(i) == t.charAt(j))
            ans += rec(i+1,j+1,s,t);
        ans += rec(i+1,j,s,t);

        flags[i][j] = true;
        return dp[i][j] = ans;
    }


    public int numDistinct(String s, String t){
        return rec(0,0,s,t);
    }
}