class Solution {
public:
    int m ,n;
    int dp[1001][1001];
    int rec(int i ,int j ,string& s,string& t){
        if(i >= m || j >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = -1e9;
        if(s[i] == t[j])
            ans = max(ans,rec(i+1,j+1,s,t) + 1);
        else{
            ans = max(ans,rec(i+1,j,s,t));
            ans = max(ans,rec(i,j+1,s,t));
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string s, string t){
        m = s.length();
        n = t.length();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,0,s,t);
        if(ans < 0)
            ans = 0;
        return ans;
    }
};