class Solution {
public:

    vector<vector<int>> adj;

    long long dfs(int u ,int p ,vector<int>& bt){

        long long finish = bt[u];
        bool leaf = true;

        long long lat = 0 ,ear = 1e18;
        for(int v : adj[u]){
            if(v == p)
                continue;

            leaf = false;
            long long ch_finish = dfs(v,u,bt);
            lat = max(lat,ch_finish);
            ear = min(ear,ch_finish);
        }

        if(!leaf)
            finish = ((lat + (lat - ear + finish)));

        return finish;
    }


    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime){

        adj.resize(n);
        for(vector<int> e : edges){
            int u = e[0] ,v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(0,-1,baseTime);
    }
};