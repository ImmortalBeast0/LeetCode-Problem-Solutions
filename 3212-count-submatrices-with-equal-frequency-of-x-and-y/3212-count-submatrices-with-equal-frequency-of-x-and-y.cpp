#include<bits/stdc++.h>
using namespace std;

#define mod (int)1e9+7
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

class Solution {
public:
    int m ,n;

    int get(char c){
        if(c == 'X')
            return 1;
        else if(c == 'Y')
            return -1;
        else
            return 0;
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        m = sz(grid);
        n = sz(grid[0]);
        vii g(m+1,vi(n+1));
        vii x(m+1,vi(n+1));
        int ans = 0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                g[i][j] += get(grid[i-1][j-1]) + g[i][j-1] + g[i-1][j] - g[i-1][j-1];
                x[i][j] += (get(grid[i-1][j-1]) > 0) + x[i][j-1] + x[i-1][j] - x[i-1][j-1];
                ans += (g[i][j] == 0) && (x[i][j] > 0); 
            }

        return ans;
    }
};