#include<bits/stdc++.h>
using namespace std;

#define mod (int)1e9+7
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

#include<bits/stdc++.h>
using namespace std;

#define mod (int)1e9+7
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

class Solution {
public:
    int m,n;
    bool done[16][16];
    pair<long,long> dp[16][16];

    pair<long,long> rec(int i ,int j ,vii& g){

        if(i == m-1 && j == n-1)
            return {g[i][j],g[i][j]};

        if(done[i][j])
            return dp[i][j];

        pair<long,long> ans = {-1e9,1e9};
        if(i+1 < m){
            pair<long,long> p1 = rec(i+1,j,g);

            ans.F = max(ans.F,g[i][j] * (p1.F));
            ans.F = max(ans.F,g[i][j] * p1.S);

            ans.S = min(ans.S,g[i][j] * p1.F);
            ans.S = min(ans.S,g[i][j] * p1.S);

        }

        if(j + 1 < n){
            pair<long,long> p2 = rec(i,j+1,g);

            ans.F = max(ans.F,g[i][j] * (p2.F));
            ans.F = max(ans.F,g[i][j] * p2.S);

            ans.S = min(ans.S,g[i][j] * p2.F);
            ans.S = min(ans.S,g[i][j] * p2.S);
        }

        done[i][j] = true;

        return dp[i][j] = ans;
    }

    int maxProductPath(vector<vector<int>>& grid) {
        
        m = sz(grid);
        n = sz(grid[0]);
        memset(done,0,sizeof(done));
        long ans = rec(0,0,grid).F;
        if(ans < 0)
            ans = -1;
        ans %= mod;
        return ans;
    }
};