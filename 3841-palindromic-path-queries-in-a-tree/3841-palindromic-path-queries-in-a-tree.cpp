#include <bits/stdc++.h>
using namespace std;

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
#define sz(x) x.size()

#define mod (1e9) + 7
#define inf 1e9

using ll = long long;

class Solution {
public:
    int n;
    vii g;
    string s;

    vii parents;
    vi in ,out;
    vi depth;

    vector<ll> BIT;

    int t = 1;
    void dfs(int u ,int p ,int d){
       in[u] = t;
       t += 1; 
       depth[u] = d;

       parents[0][u] = p;
       for(int i=1;i<20;i++)
            parents[i][u] = parents[i-1][parents[i-1][u]];

        for(int v : g[u])
            if(v != p)
                dfs(v,u,d+1);
                
        out[u] = t;
        t += 1;
    }

    void update(int id ,int val){
        while(id < sz(BIT)){
            BIT[id] ^= val;
            id += id & (-id);
        }
    }

    ll query(int id){
        ll ans = 0;
        while(id > 0){
            ans ^= BIT[id];
            id -= id & (-id);    
        }
        return ans;
    }

    int lca(int u ,int v){
        if(depth[u] < depth[v])
            swap(u,v);

        int diff = depth[u] - depth[v];

        for(int i=0;i<20;i++)
            if(diff & ( 1 << i))
                u = parents[i][u];
        
        if(u == v)
            return u;

        for(int i=19;i>=0;i--)
            if(parents[i][u] != parents[i][v]){
                u = parents[i][u];
                v = parents[i][v];
            }

        return parents[0][u];
    }

    vector<string> extract(string q){
        stringstream ss(q);
        string val;
        vector<string> ans;
        while(getline(ss,val,' ')){
            ans.pb(val);
        }
        return ans;
    }

    vector<bool> palindromePath(int n_, vii& edges, string s_, vector<string>& queries) {
        
        n = n_;
        s = s_;
        t = 1;
        g.clear();g.resize(n+1);
        parents.clear();parents.resize(20,vi(n+1));
        depth.clear();depth.resize(n+1);
        in.clear();in.resize(n+1);
        out.clear();out.resize(n+1);

        BIT.clear();BIT.resize(2 * (n + 1));

        for(auto e : edges){
            int u = e[0] ,v = e[1];
            u += 1; v += 1;
            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(1,0,0);
        
        for(int i=1;i<=n;i++){
            update(in[i],(1 << (s[i-1]-'a')));
            update(out[i],(1 << (s[i-1]-'a')));
        }

        vector<bool> sol;
        for(string quer : queries){
            vector<string> q = extract(quer);
            if(q[0] == "update"){
                int u = stoi(q[1]);
                u += 1;
                char v = q[2][0];
                ll updatedVal = (1 << (v - 'a')) ^ (1 << (s[u-1] - 'a'));
                s[u-1] = v;
                update(in[u],updatedVal);
                update(out[u],updatedVal);
            }else{
                int u = stoi(q[1]);
                int v = stoi(q[2]);
                u += 1;
                v += 1;
                ll num = query(in[u]);
                num ^= query(in[v]);
                num ^= (1 << s[lca(u,v)-1] - 'a');
                sol.pb((__builtin_popcountll(num) <= 1));
            }
        }

        return sol;
    }
};