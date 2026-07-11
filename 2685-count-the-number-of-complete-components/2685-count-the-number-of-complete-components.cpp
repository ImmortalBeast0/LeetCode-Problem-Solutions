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
    vector<bool> vis;
    vector<vector<int>> adj;
    vector<int> comp;
    unordered_map<int,vector<int>> mp;
    // Component Number ,Vertices

    void dfs(int u ,int c){
        mp[c].push_back(u);
        vis[u] = true;
        for(int v : adj[u])
            if(!vis[v])
                dfs(v,c);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges){

        adj.resize(n);
        vis.resize(n);
        for(vector<int> e : edges){
            int u = e[0] ,v = e[1];
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int c = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,c);
                comp.push_back(mp[c].size());
                c += 1;
            }
        }
        int sol = 0;

        for(auto &[c,a] : mp){
            bool flag = true;
            for(int u : a)
                if(adj[u].size() +1 != comp[c]){
                    flag = false;
                    break;
                }
            if(flag)
                sol += 1;
        }

        return sol;
    }
};