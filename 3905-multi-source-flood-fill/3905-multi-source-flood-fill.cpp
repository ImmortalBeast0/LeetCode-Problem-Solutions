#define vii vector<vector<int>>
#define F first
#define S second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

class Solution {
public:
    int n ,m;

    bool check(int i ,int j){
        return i >=0 && i < n && j >=0 && j < m;
    }

    vii colorGrid(int n_, int m_, vii& src){
        n = n_;
        m = m_;
        vii vis(n,vector<int>(m));
        vii depth(n,vector<int>(m,n*m));


        queue<pair<int,int>> q;
        for(auto v : src){
            int i = v[0] ,j = v[1] ,c = v[2];
            vis[i][j] = c;
            depth[i][j] = 0;
            q.push({i,j});
        }

        int d = 1;
        while(!q.empty()){
            int sz = q.size();
            set<pair<int,int>> ss;
            while(sz--){
                pair<int,int> u = q.front();
                q.pop();
                int x = u.F ,y = u.S;
                int c = vis[x][y];
                for(int i=0;i<4;i++){
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    if(check(nx,ny) && vis[nx][ny] <= c && depth[nx][ny] >= d){
                        vis[nx][ny] = c;
                        depth[nx][ny] = d;
                        ss.insert({nx,ny});
                    }
                }
            }
            for(auto p : ss)
                q.push(p);
            d += 1;
        }


        return vis;
    }
};