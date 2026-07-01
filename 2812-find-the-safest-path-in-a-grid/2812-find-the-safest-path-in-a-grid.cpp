class Solution {
public:
    int n;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool check(int i ,int j){
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    vector<vector<int>> dist;
    vector<vector<bool>> vis;

    bool dfs(int i ,int j ,int mn){
        if(i == n-1 && j == n-1)
            return true;
        vis[i][j] = true;
        for(int d=0;d<4;d++){
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(check(ni,nj) && dist[ni][nj] >= mn && !vis[ni][nj]){
                if(dfs(ni,nj,mn))
                    return true;
            }
        }
        return false;
    }

    bool check(int mn){
        if(dist[0][0] < mn)
            return false;
        vis.assign(n,vector<bool>(n,false));
        return dfs(0,0,mn);
    }

    int maximumSafenessFactor(vector<vector<int>>& g){
        
        n = g.size();
        dist.assign(n,vector<int>(n,n+n));

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(g[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }

        while(!q.empty()){
            int ui = q.front().first;
            int uj = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int vi = ui + dx[d];
                int vj = uj + dy[d];
                if(check(vi,vj) && dist[vi][vj] > dist[ui][uj] + 1){
                    dist[vi][vj] = dist[ui][uj] + 1;
                    q.push({vi,vj});
                }
            }    
        }   

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << dist[i][j] << ' ';
            cout << endl;
        }

        int lb = 0 ,ub = n+n ,ans = 0;
        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            if(check(mi)){
                ans = mi;
                lb = mi + 1;
            }else
                ub = mi - 1;
        }

        return ans;
    }
};