#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>

#define F first
#define S second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()

class Solution {
public:

    int max_depth;
    int dp[(int)(1 + 1e5)][3];

    int rec(int i ,int sum){

        if(i >= max_depth)
            return sum;

        if(dp[i][sum] != -1)
            return dp[i][sum];

        int ans = 0;
        ans += rec(i+1,0);
        ans %= mod;
        ans += rec(i+1,1);
        ans %= mod;
        return dp[i][sum] = ans;
    }

    int n;
    vii adj;

    void dfs(int u ,int p ,int d){
        max_depth = max(max_depth,d);
        for(int v : adj[u]){
            if(v == p)
                continue;
            dfs(v,u,d+1);
        }
    }

    int assignEdgeWeights(vii& edges){
        n = edges.size() + 1;
        adj.resize(n);
        for(vi e : edges){
            int u = e[0] ,v = e[1];
            u -= 1;
            v -= 1;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0,-1,0);
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};

