class Solution {
public:
    int m ,n;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool c(int i ,int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool findSafeWalk(vector<vector<int>>& g, int health) {
        m = g.size();
        n = g[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        deque<pair<int,int>> dq;
        dist[0][0] = g[0][0];
        dq.push_front({0,0});

        while(!dq.empty()){
            int i = dq.front().first;
            int j = dq.front().second;
            dq.pop_front();

            for(int d=0;d<4;d++){
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(c(ni,nj) && dist[ni][nj] > g[ni][nj] + dist[i][j]){
                    dist[ni][nj] = g[ni][nj] + dist[i][j];
                    if(g[ni][nj])
                        dq.push_back({ni,nj});
                    else
                        dq.push_front({ni,nj});
                }
            }
        }

        return (health - dist[m-1][n-1]) >= 1;
    }
};