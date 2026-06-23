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

    vector<vpi> adj;

    int findCheapestPrice(int n, vii& flights, int src, int dst, int k) {
        adj.resize(n);

        for(vi f : flights){
            int u = f[0] ,v = f[1] ,w = f[2];
            adj[u].pb({v,w});
        }

        vector<vector<int>> dist(n,vector<int>(k+2,1e9));
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        dist[src][0] = 0;
        pq.push({dist[src][0],src,0});

        while(!pq.empty()){
            int u = pq.top()[1];
            int d_u = pq.top()[0];
            int cnt_u = pq.top()[2]; 
            pq.pop();

            if(d_u > dist[u][cnt_u])
                continue;

            for(pi p : adj[u]){
                int v = p.F;
                int w = p.S;
                if(cnt_u + 1 <= (k + 1) && dist[v][cnt_u+1] > d_u + w){
                    dist[v][cnt_u+1] = d_u + w;
                    pq.push({dist[v][cnt_u+1],v,cnt_u+1});
                }
            }
        }

        int ans = *min_element(all(dist[dst]));
        if(ans >= (int)1e9)
            ans = -1;
        return ans;
    }
};
