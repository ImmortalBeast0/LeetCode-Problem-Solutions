#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

class Solution {
public:

    int n ,score;
    int dp[105][105][105];
    int rec(int i ,int cnt ,int sc ,vi& g ,vi& profit){
        if(i >= g.size())
            return cnt <= n && sc >= score;

        if(cnt > n)
            return 0;

        if(dp[i][cnt][sc] != -1)
            return dp[i][cnt][sc];

        int ans = 0;
        ans += rec(i+1,cnt+g[i],min(101,sc+profit[i]),g,profit);
        ans %= mod;
        ans += rec(i+1,cnt,sc,g,profit);
        ans %= mod;


        return dp[i][cnt][sc] = ans;
    }

    int profitableSchemes(int n_, int minProfit, vector<int>& group, vector<int>& profit) {
        n = n_;
        score = minProfit;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,group,profit);
    }
};