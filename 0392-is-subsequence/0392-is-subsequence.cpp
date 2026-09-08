class Solution {
public:
    int m,n;
    int dp[100032][132];
    bool rec(int i,int j,string t,string s){

        if(dp[i][j] != -1)
            return dp[i][j];
        if(n == j){
            return true;
        }
        if(m == i)
            return false;
        
        if(t[i] == s[j]){
            if(rec(i+1,j+1,t,s))
                return dp[i][j] = true;
        }else if(rec(i+1,j,t,s))
            return dp[i][j] = true;

        return dp[i][j] = false;

    }

    bool isSubsequence(string s, string t) {
        m = t.size();
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,t,s);    
    }
};