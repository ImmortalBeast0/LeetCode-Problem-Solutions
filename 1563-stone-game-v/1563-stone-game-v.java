class PrefixSum{
    int n;
    int[] ps;
    void build(int[] nums){
        n = nums.length;
        ps = new int[n+1];
        ps[0] = nums[0];
        for(int i=1;i<n;i++)
            ps[i] += ps[i-1] + nums[i];
    }

    int getRange(int l ,int r){
        if(l == 0)
            return ps[r];
        return ps[r] - ps[l-1];
    }
}


class Solution {
    int n; 
    PrefixSum st;

    int iter(){
        int[][] dp = new int[n+1][n+1];
        for(int len=0;len<=n;len++){
            for(int i=0;i+len < n;i++){
                int j  = i + len;
                if(i == j)
                    dp[i][j] = 0;
                else{
                    dp[i][j] = (int)-1e9;
                    for(int k=i;k<j;k++){
                        int lt = st.getRange(i,k);
                        int rt = st.getRange(k+1,j);
                        if(lt == rt){
                            dp[i][j] = Math.max(dp[i][j],Math.max(dp[i][k] + lt,dp[k+1][j] + rt));
                        }else{
                            if(lt > rt)
                                dp[i][j] = Math.max(dp[i][j],dp[k+1][j] + rt);
                            else
                                dp[i][j] = Math.max(dp[i][j],dp[i][k] + lt);
                        }
                    }
                }
            }
        }

        return dp[0][n-1];
    }

    public int stoneGameV(int[] stoneValue) {
        st = new PrefixSum();
        st.build(stoneValue);
        n = stoneValue.length;
        return iter();
    }
}