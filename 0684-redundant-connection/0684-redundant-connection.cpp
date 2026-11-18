class Solution{
public:

    vector<int> par;
    vector<int> rk;

    void init(int n){
        par.resize(n);
        rk.resize(n,0);
        for(int i=0;i<n;i++)
            par[i] = i;
    }

    int find(int u){
        if(par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }

    bool join(int u ,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
            return false;
        if(rk[pu] < rk[pv])
            swap(pu,pv);
        par[pv] = pu;
        if(rk[pu] == rk[pv])
            rk[pu] += 1;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        
        init(edges.size() + 1);
        for(vector<int> e : edges){
            if(!join(e[0],e[1]))
                return {e[0],e[1]};
        }

        return {};
    }    
};