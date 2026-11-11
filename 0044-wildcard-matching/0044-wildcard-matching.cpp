class Solution {
public:
    int m , n;
    int dp[2002][2002];
    bool rec(int i ,int j ,string &s ,string &t){

        if(i >= m && j >= n)
            return true;

        if((i < m && j >= n))
            return false;

        if(i >= m && j < n){
            for(int k=j;k<n;k++)
                if(t[k] != '*')
                    return false;
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;
        if(s[i] == t[j] || t[j] == '?'){
            ans |= rec(i+1,j+1,s,t);
        }else if(t[j] == '*'){                
            ans |= rec(i+1,j,s,t);
            ans |= rec(i,j+1,s,t);
            ans |= rec(i+1,j+1,s,t);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string t) {
        m = s.length();
        n = t.length();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,t);
    }
};