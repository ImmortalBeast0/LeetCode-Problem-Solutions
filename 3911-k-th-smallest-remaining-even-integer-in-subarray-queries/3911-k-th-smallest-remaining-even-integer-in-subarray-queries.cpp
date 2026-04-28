#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9+7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()

class Solution {
public:

    int n;
    vector<ll> ps;

    ll getSum(int l ,int r){
        if(r < l)
            return 0;
        ll ans = ps[r];
        if(l > 0)
            ans -= ps[l-1];
        return ans;
    }

    bool check(ll num,ll l ,ll r ,ll k ,vi& nums){
        int idx = upper_bound(nums.begin()+l,nums.begin()+r+1,num) - nums.begin() - 1; 
        ll cnt = 0;
        if(idx >= l)
            cnt = getSum(l,idx);
        return (num/2 - cnt) >= k;
    }

    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        ps.resize(n,0);
        ps[0] = !(nums[0] % 2);
        for(int i=1;i<n;i++)
            ps[i] = ps[i-1] + !(nums[i] % 2);

        vi sol;
        for(vi q : queries){
            int l = q[0] ,r = q[1] ,k = q[2];
            ll ans ,lb = 2 ,ub = 1e18 ,mi; 
            while(lb <= ub){
                mi = (ub - lb)/2 + lb;
                if(check(mi,l,r,k,nums)){
                    ans = mi;
                    ub = mi - 1;
                }else
                    lb = mi + 1;
            }
            if(ans % 2) 
                ans -= 1;
            sol.pb(ans);
        }

        return sol;
    }
};