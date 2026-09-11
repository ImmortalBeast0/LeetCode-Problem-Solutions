class Solution {
    final int mod = (int)1e9 + 7;
    long[][][][] dp;
    long rec(int pos ,boolean st ,boolean tight ,int pre ,int[] nums){

        if(pos >= nums.length)
            return 1;

        if(dp[pos][st ? 1 : 0][tight ? 1 : 0][pre] != -1)
            return dp[pos][st ? 1 : 0][tight ? 1 : 0][pre];

        long ans = 0;
        int lb = 0 ,ub = tight ? nums[pos] : 9;

        for(int i=lb;i<=ub;i++){
            boolean nst = st || i > 0;
            boolean ntight = tight && i >= nums[pos];
            if(!st || Math.abs(pre - i) == 1)
                ans += rec(pos+1,nst,ntight,i,nums);
            ans %= mod;
        }

        return dp[pos][st ? 1 : 0][tight ? 1 : 0][pre] = ans;
    }

    public int countSteppingNumbers(String ll, String hh) {
        
        int[] low = new int[ll.length()];
        int sub = 1;
        char[] tmp = ll.toCharArray();
        int i = tmp.length - 1;
        for(int k=tmp.length - 1 ;k>=0;k--){
            char c = tmp[k];
            int dig = c - '0';
            if(dig - sub >= 0){
                dig -= sub;
                sub = 0;
            }else{
                dig += 10;
                dig -= sub;
            }
            low[i--] = dig;
        }
        
        i = 0;
        int[] high = new int[hh.length()];
        for(char c : hh.toCharArray())
            high[i++] = (c - '0');
        
        
        dp = new long[132][3][3][11];
        fill(dp);
        long ub = rec(0,false,true,10,high);
        fill(dp);
        long lb = rec(0,false,true,10,low);
        return (int) (ub - lb + mod) % mod;
    }

    void fill(long[][][][] dp){
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<dp[i].length;j++){
                for(int k=0;k<dp[i][j].length;k++)
                    Arrays.fill(dp[i][j][k],-1);
            }
        }
    }
}