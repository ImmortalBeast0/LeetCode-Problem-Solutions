#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9+7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define F first
#define S second 
#define all(x) x.begin(),x.end()

class Solution {
public:

    int m ,n;
    vii ps;

    void calc(vii& mat){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ps[i][j] = mat[i][j];
                if(i-1 >= 0)
                    ps[i][j] += ps[i-1][j];
                if(j -1 >= 0)
                    ps[i][j] += ps[i][j-1];
                if(i-1 >= 0 && j-1 >= 0)
                    ps[i][j] -= ps[i-1][j-1];
            }
        }
    }

    int get(int i , int j ,int k ,int l){
        int sol = ps[k][l];
        if(i > 0) sol -= ps[i-1][l];
        if(j > 0) sol -= ps[k][j-1];
        if(i > 0 && j > 0) sol += ps[i-1][j-1];
        return sol;
    }

    bool check(int k ,vii& mat){
        int cnt = 0;
        int mxr ,mnr ,mxc ,mnc;
        mxr = mxc = -1e9;
        mnr = mnc = 1e9;
        for(int i=k-1;i<m;i++){
            for(int j=k-1;j<n;j++){
                int l = i - (k - 1);
                int r = j - (k - 1);
                if(get(l,r,i,j) == k * k){
                    cnt += 1;
                    mnr = min(mnr,l);mxr = max(mxr,l);
                    mnc = min(mnc,r);mxc = max(mxc,r);
                }
            }
        }

        if(cnt < 2)
            return false;

        return (mxr - mnr) >= k || (mxc - mnc) >= k;
    }   

    int maxArea(vector<vector<int>>& mat) {

        m = mat.size();
        n = mat[0].size();
        ps.resize(m,vector<int>(n));
        calc(mat);
        int lb = 1 ,ub = 500;
        int ans = 0;
        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            if(check(mi,mat)){
                ans = mi;
                lb = mi + 1;
            }else
                ub = mi - 1;
        }

        return ans * ans;
    }
};