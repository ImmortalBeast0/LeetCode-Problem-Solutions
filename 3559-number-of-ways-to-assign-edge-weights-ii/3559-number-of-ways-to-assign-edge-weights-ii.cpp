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
    bool flag = true;
    int pow_2[2 + (int)1e5];

    void calc(){
        flag = false;
        pow_2[0] = 1;
        for(int i=1;i<2+(int)1e5;i++)
            pow_2[i] = (2 * pow_2[i-1]) % mod;
    }

    int n;
    vii adj;
    vi depth;
    vii par;

    void dfs(int u = 0,int p = -1,int d = 0){

        depth[u] = d;
        par[0][u] = p;

        for(int i=1;i<20;i++){
            if(par[i-1][u] != -1)
                par[i][u] = par[i-1][par[i-1][u]];
        }

        for(int v : adj[u]){
            if(v == p)
                continue;
            dfs(v,u,d+1);
        }
    }

    int findLCA(int u ,int v){

        if(depth[u] < depth[v])
            swap(u,v);

        int diff = depth[u] - depth[v];
        int p_u = u;
        int p_v = v;

        int i = 0;
        while(diff){
            if(diff & 1){
                p_u = par[i][p_u];
            }
            diff >>= 1;
            i += 1;
        } 

        if(p_u == p_v)
            return p_u;

        for(int i=19;i>=0;i--){
            if(par[i][p_u] != par[i][p_v]){
                p_u = par[i][p_u];
                p_v = par[i][p_v];
            }
        }

        return par[0][p_u];
    }

    vi assignEdgeWeights(vii& edges, vii& queries) {
        if(flag)
            calc();
        n = edges.size() + 1;

        adj.resize(n);
        depth.resize(n);
        par.resize(20,vector<int>(n,-1));

        for(vi e : edges){
            int u = e[0] ,v = e[1];
            u -= 1; v -= 1;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs();
        vi ans;
        for(vi q : queries){
            int u = q[0] ,v = q[1];
            u -= 1; v -= 1;
            int lca = findLCA(u,v);
            int dist = depth[u] + depth[v] - (2 * depth[lca]); 
            if(dist == 0)
                ans.pb(0);
            else
                ans.pb(pow_2[dist - 1]);
        }

        return ans;
    }
};