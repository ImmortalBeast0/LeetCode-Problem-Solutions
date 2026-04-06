#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod ((int)1e9+7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>
#define pb push_back
#define bp pop_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
class Solution {
public:
    int n;
    vii g;
    vi vis;
    vi indeg;
    int sol;

    void dfs(int u ,int d){
        vis[u] = 1;
        sol = max(sol,d);
        for(int v : g[u])
            if(!vis[v])
                dfs(v,d+1);
    }

    int longestCycle(vector<int>& edges) {
        
        n = edges.size();
        g.resize(n);
        vis.resize(n,0);
        indeg.resize(n,0);
        sol = 0;

        for(int u=0;u<n;u++){
            int v = edges[u];
            if(v == -1) continue;
            g[u].pb(v);
            indeg[v]++;
        }

        int cnt = 0;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indeg[i] == 0){
               vis[i] = 1;
               q.push(i);
            } 

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : g[u]){
                indeg[v] -= 1;
                if(indeg[v] == 0){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        for(int i=0;i<n;i++)
            if(vis[i] == 0){
                dfs(i,01);
            }
        
        if(sol == 0)
            sol = -1;
        return sol;
    }
};