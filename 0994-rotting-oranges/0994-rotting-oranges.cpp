#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
class Solution {
public:
    int m ,n;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool check(int i ,int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int orangesRotting(vii& g){

        m = g.size() ,n = g[0].size();

        queue<pi> q;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(g[i][j] == 2)
                    q.push({i, j});
        
        int d = 0;
        while(!q.empty()){
            bool flag = false;
            int sz = q.size();
            while(sz--){
                pi u = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int ni = dx[i] + u.F;
                    int nj = dy[i] + u.S;
                    if(check(ni,nj) && g[ni][nj] == 1){
                        g[ni][nj] = 2;
                        q.push({ni,nj});
                        flag = true;
                    }
                }
            }
            d += flag;
        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(g[i][j] == 1)
                    return -1;

        return d;
    }
};