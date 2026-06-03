#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define F first
#define S second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()

class Solution {
public:

    int bs(vpi &arr ,int key){

        int n = arr.size();
        int lb = 0 ,ub = n-1;
        while(lb <= ub){
            int mi = (lb + ub)/2;
            if(arr[mi].F == key)
                return mi;
            else if(arr[mi].F < key)
                lb = mi + 1;
            else
                ub = mi - 1;
        }

        return lb - 1;
    }

    int earliestFinishTime(vi& lst, vi& ld, vi& wst, vi& wd){

        int n = lst.size();
        int m = wst.size();

        vpi land;
        for(int i=0;i<n;i++)
            land.pb({lst[i],ld[i]});
            
        vpi water;
        for(int i=0;i<m;i++)
            water.pb({wst[i],wd[i]});
        
        sort(all(land));
        sort(all(water));

        int ans = 1e9;

        vi pxl(n);
        pxl[0] = land[0].S;
        for(int i=1;i<n;i++)
            pxl[i] = min(pxl[i-1],land[i].S);

        vi sxl(n);
        sxl[n-1] = land[n-1].F + land[n-1].S;
        for(int i=n-2;i>=0;i--)
            sxl[i] = min(sxl[i+1],land[i].F + land[i].S);


        vi pxw(m);
        pxw[0] = water[0].S;
        for(int i=1;i<m;i++)
            pxw[i] = min(pxw[i-1],water[i].S);
        
        vi sxw(m);
        sxw[m-1] = water[m-1].F + water[m-1].S;
        for(int i=m-2;i>=0;i--)
            sxw[i] = min(sxw[i+1],water[i].F + water[i].S);


        for(int i=0;i<n;i++){
            int end = land[i].F + land[i].S;
            int idx = bs(water,end);
            if(idx >= 0)
                ans = min(ans,end+pxw[idx]);
            if(idx+1 < m)
                ans = min(ans, sxw[idx + 1]);
        }
        for(int i=0;i<m;i++){
            int end = water[i].F + water[i].S;
            int idx = bs(land,end);
            if(idx >= 0)
                ans = min(ans,end+pxl[idx]);
            if(idx + 1 < n)
                ans = min(ans, sxl[idx + 1]);
        }

        return ans;
    }
};