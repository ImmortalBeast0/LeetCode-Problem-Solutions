class Solution {
public:
    int n;
    set<string> ss;

    bool isExist(string s){
        return ss.find(s) != ss.end();
    }

    int dp[303];
    bool rec(int i ,string &s){
        if(i >= n)
            return true;

        if(dp[i] != -1)
            return dp[i];

        bool ans = false;
        for(int j=i;j<n;j++){
            if(isExist(s.substr(i,j - i + 1)))
                if(rec(j+1,s)){
                    ans = true;
                    break;
                }
        }

        return dp[i] = ans;
    }

    bool wordBreak(string s, vector<string>& wd) {
        n = s.length();
        for(string w : wd)
            ss.insert(w);
        memset(dp,-1,sizeof(dp));
        return rec(0,s);
    }
};