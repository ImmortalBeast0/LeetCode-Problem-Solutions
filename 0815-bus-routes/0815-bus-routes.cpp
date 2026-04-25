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

    bool haveCommonNode(vi& r1 ,vi& r2){
        int i = 0, j = 0;
        bool f = false;
        while(i < r1.size() && j < r2.size()){
            if(r1[i] == r2[j]){
                f = true;
                break;
            }
            r1[i] < r2[j] ? i++ : j++;
        }

        return f;
    }

    bool isNodeExistRoute(vi& route ,int node){
        int idx = lower_bound(all(route),node) - route.begin();
        return idx >= 0 && idx < route.size() && route[idx] == node;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        int nr = routes.size();
        for(int i=0;i<nr;i++)
            sort(all(routes[i]));

        vii g(nr);
        vector<bool> vis(nr,0);
        queue<int> q;
        map<int,int> vis_stops;
        for(int i=0;i<nr;i++)
            for(int j=i+1;j<nr;j++)
                if(haveCommonNode(routes[i],routes[j])){
                    g[i].pb(j);
                    g[j].pb(i);
                }

        vis_stops[source] = 1;
        for(int i=0;i<nr;i++){
            if(isNodeExistRoute(routes[i],source)){
                q.push(i);
                vis[i] = 1;
            }
        }

        int busStops = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();
                if(isNodeExistRoute(routes[u],target))
                    return busStops;
                for(int v : g[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            busStops += 1;
        }

        return -1;
    }
};