class SparseTable{
    final int K  = 10;
    int n;
    int st[][];
    void build(int[] arr){
        n = arr.length;
        st = new int[K][n+2];

        for(int i=0;i<n;i++)
            st[0][i] = arr[i];

        for(int i=1;i<K;i++){
            for(int j=0;j + (1 << (i-1)) <= n;j++){
                st[i][j] = st[i-1][j] + st[i-1][j + (1 << (i-1))];
            }
        }
    }

    int getRange(int l ,int r){
        int ans = 0;
        for(int i=K-1;i>=0;i--){
            if((1 << i) <= (r - l + 1)){
                ans += st[i][l];
                l += (1 << i);
            }
        }

        return ans;
    }
}


class Solution {
    int n; 
    SparseTable st;
    int dp[][];
    int rec(int i ,int j){

        if(i == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = (int)-1e9;
        for(int k=i;k<j;k++){
            int lt = st.getRange(i,k);
            int rt = st.getRange(k+1,j);
            if(lt == rt){
                ans = Math.max(ans,Math.max(rec(i,k) + lt,rec(k+1,j) + rt));
            }else{
                if(lt > rt)
                    ans = Math.max(ans,rec(k+1,j) + rt);
                else
                    ans = Math.max(ans,rec(i,k) + lt);
            }
        }

        return dp[i][j] = ans;
    }

    int iter(){
        int[][] dp = new int[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=i;j<n;j++){
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
        st = new SparseTable();
        st.build(stoneValue);
        n = stoneValue.length;
        dp = new int[n+1][n+1];
        for(int i=0;i<=n;i++)
            Arrays.fill(dp[i],-1);
        return rec(0,n-1);
    }
}