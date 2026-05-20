class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<vector<int>> adj;
    vector<int> vis;
    void dfs(int u ,int alpha){

        if(u != alpha)
            ans[u].push_back(alpha);
        
        vis[u] = 1;
        for(int v : adj[u]){
            if(!vis[v])
                dfs(v,alpha);
        }
    }

    vector<vector<int>> getAncestors(int n_, vector<vector<int>>& edges){

        n = n_;
        adj.resize(n);
        ans.resize(n);
        for(vector<int> e : edges){
            int u = e[0] ,v = e[1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<n;i++){
            vis.assign(n,0);
            dfs(i,i);
        }

        return ans;
    }
};