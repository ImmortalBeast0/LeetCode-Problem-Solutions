class Solution {
public:

    vector<int> par;
    vector<int> sz;

    void init(int n){
        par.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
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
        if(sz[pu] < sz[pv])
            swap(pu,pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        init(n);
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1,x2,y1,y2;
                x1 = points[i][0];
                y1 = points[i][1];
                x2 = points[j][0];
                y2 = points[j][1];
                edges.push_back({abs(x2 - x1) + abs(y2 - y1),i,j});
            }
        }

        sort(edges.begin(),edges.end());
        int sol = 0;
        int cnt = 1;
        for(vector<int> e : edges){
            if(cnt >= n)
                break;
            int u = e[1] ,v = e[2];
            int w = e[0];
            if(join(u,v)){
                sol += w;
                cnt += 1;
            }
        }

        return sol;
    }
};