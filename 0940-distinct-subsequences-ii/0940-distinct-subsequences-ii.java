class Solution {

    public int distinctSubseqII(String str) {
        char[] s = str.toCharArray();
        final int mod = (int)1e9 + 7;
        int n = str.length();
        int[] dp = new int[n+1];
        dp[0] = 1;
        int[] last = new int[26];
        Arrays.fill(last,-1);
        for(int i=0;i<n;i++){
            dp[i+1] = (dp[i] * 2) % mod;
            int id = s[i] - 'a';
            if(last[id] != -1)
                dp[i+1] = (dp[i+1] - dp[last[id]] + mod) % mod;
            last[id] = i;
        }
        return (dp[n] - 1 + mod) % mod;
    }
}