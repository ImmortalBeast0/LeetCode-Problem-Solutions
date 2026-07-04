class Solution {
public:

    vector<int> par;
    vector<int> val;

    int find(int u){
        if(u == par[u])
            return u;
        return par[u] = find(par[u]);
    }

    void mergeg(int u ,int v ,int w){
        int pu = find(u);
        int pv = find(v);
        val[pu] = min({w,val[pu],val[pv]});
        if(pu == pv)
            return ;
        par[pv] = pu; 
    }

    int minScore(int n, vector<vector<int>>& roads) {
        par.resize(n);
        val.resize(n);

        for(int i=0;i<n;i++){
            par[i] = i;
            val[i] = 1e9;
        }

        for(auto e : roads){
            int u = e[0],v= e[1] ,w = e[2];
            u -= 1; v -= 1;
            mergeg(u,v,w);
        }

        return val[find(0)];
    }
};