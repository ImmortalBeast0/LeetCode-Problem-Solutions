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
    long long k;
    vector<vpi> adj;

    bool check(int min_edge){

        vector<ll> dist(n,1e18);
        priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>> pq;

        dist[0] = 0;
        pq.push({dist[0],0});

        while(!pq.empty()){
            int u = pq.top()[1];
            ll d = pq.top()[0];
            pq.pop();
            if(d != dist[u])
                continue;
            
            for(auto x : adj[u]){
                int v = x.F;
                int w = x.S;
                if(w >= min_edge && dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v],v});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vii& edges, vector<bool>& online ,ll k_){

        n = online.size();
        k = k_;
        adj.resize(n);

        int mx = 2*-1e9,mn = 2*1e9;

        for(auto e : edges){
            int u = e[0] ,v = e[1] ,w = e[2];
            if(online[u] && online[v]){
                adj[u].pb({v,w});
                mx = max(mx,w);
                mn = min(mn,w);
            }
        }


        int ans = -1;
        int lb = mn ,ub = mx;
        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            if(check(mi)){
                ans = mi;
                lb = mi + 1;
            }else
                ub = mi - 1;
        }

        return ans;
    }
};