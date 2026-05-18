class Solution {
public:

    bool dfs(int u ,int color ,vector<vector<int>>& adj ,vector<int>& vis){

        vis[u] = color;
        for(int v : adj[u]){
            if(vis[v] == -1)
                if(!dfs(v,1 - color,adj,vis))
                    return false;
            if(vis[v] == vis[u])
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        
        vector<int> vis(adj.size(),-1);
        for(int i=0;i<adj.size();i++)
            if(vis[i] == -1 && !dfs(i,0,adj,vis))
                return false;

        return true;
    }
};