class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold){
        const int inf = 2e9;
        vector<vector<int>> dist(n,vector<int>(n,inf));
        
        for(int i=0;i<n;i++)
            dist[i][i] = 0;

        for(vector<int> e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[u][v] = dist[v][u] = w;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] != inf && dist[k][j] != inf)
                        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = 0;
        int mn = inf;

        for(int i=0;i<n;i++){
            int cur = 0;
            for(int j=0;j<n;j++)
                cur += (dist[i][j] <= threshold);
            if(cur <= mn){
                mn = cur;
                ans = i;
            }
        }

        return ans;
    }
};