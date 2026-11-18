class Solution {
public:
    int n;
    unordered_map<int,unordered_map<int,int>> dp;
    int rec(int i ,int j ,vector<int>& cuts){
        
        if(dp.find(i) != dp.end())
            if(dp[i].find(j) != dp[i].end())
                return dp[i][j];
        

        int ans = 1e9;
        bool f = true;
        for(int k=0;k<cuts.size();k++){
            if(cuts[k] > i && cuts[k] < j){
                ans = min(ans,rec(i,cuts[k],cuts) + rec(cuts[k],j,cuts) + j - i);
                f = false;
            }
        }

        if(f)
            ans = 0;

        return dp[i][j] = ans;
    }

    int minCost(int n_, vector<int>& cuts) {
        n = n_;
        if(cuts.size() == 1)
            return n;
        return rec(0,n,cuts);
    }
};