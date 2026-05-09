#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9 + 7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
class Solution {
public:

    int n;
    vector<vpi> g;

    bool check(int thresh ,int src ,int tar ,int k){

        deque<int> q;
        vector<int> dist(n,1e9);

        q.push_back(src);
        dist[src] = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop_front();
                for(pi x : g[u]){
                    int v = x.F ,w = x.S;
                        if(dist[u] + (w > thresh) < dist[v]){
                            dist[v] = dist[u] + (w > thresh);
                            if(w > thresh)
                            q.push_back(v);
                            else
                                q.push_front(v);
                        }
                }
            }
        }

        return dist[tar] <= k;
    }

    int minimumThreshold(int n_, vector<vector<int>>& edges, int source, int target, int k) {
        if(source == target)
            return 0;
        n = n_;
        g.resize(n);
        ll lb = 0 ,ub = 1e9+1;
        for(vector<int> e : edges){
            ll u = e[0] ,v = e[1] ,w = e[2];
            // lb = min(lb,w);
            // ub = max(ub,w);
            g[u].pb({v,w});
            g[v].pb({u,w});
        }

        int ans = -1;
        while(lb <= ub){
            ll mi = (ub - lb)/2 + lb;
            if(check(mi,source,target,k)){
                ans = mi;
                ub = mi - 1;
            }else
                lb = mi + 1;
        }

        return ans;
    }
};
