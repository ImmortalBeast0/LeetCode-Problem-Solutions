class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();

        queue<pair<int,int>> q;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j] == 2)
                    q.push({i,j});
                if(g[i][j] == 1)
                    cnt += 1;
            }
        }

        if(q.size() == 0){
            if(cnt)
                return -1;
            return 0;
        }

        int mins = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int d=0;d<4;d++){
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && g[ni][nj] == 1){
                        cnt -= 1;
                        g[ni][nj] = 2;
                        q.push({ni,nj});
                    }
                }
            }
            mins += 1;
        }

        if(cnt)
            return -1;

        return mins - 1;
    }
};