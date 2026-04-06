#include<bits/stdc++.h>
using namespace std;

#define mod ((ll)1e9+7)
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
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        ll costTot = 0;
        ll tot = 0;
        vector<pi> arr;
        for(int i=0;i<n;i++){
            tot += (1ll * cost[i] * nums[i]);
            costTot += cost[i];
            arr.pb({nums[i],cost[i]});
        }

        sort(all(arr));
        ll sol = 1e18 ,ck = 0,tk = 0;
        for(int i=0;i<n;i++){
            int ci = arr[i].S ,ni = arr[i].F;
            ck += ci;
            tk += (1ll * ci * ni);
            sol = min(sol,(1ll*ni*(ck-(costTot - ck)) + (-tk + (tot - tk))));
        }

        return sol;
    }
};