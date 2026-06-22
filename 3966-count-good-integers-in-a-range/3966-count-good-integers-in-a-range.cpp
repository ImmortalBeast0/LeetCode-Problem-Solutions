#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>

#define F first
#define S second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()

class Solution {
public:

    string nums;
    ll dp[3][3][11][17];
    ll rec(int pos ,bool tight ,bool st ,int prev ,int k){

        if(pos >= nums.size())
            return 1;

        if(dp[tight][st][prev][pos] != -1)
            return dp[tight][st][prev][pos];

        ll ans = 0;
        
        int num = nums[pos] - '0';
        int lb = st ? max(0,prev-k) : 0;
        int ub;
        if(st)
            ub = tight ? min(num,prev+k) : min(9,prev + k); 
        else
            ub = tight ? num: 9;

        for(int d=lb;d<=ub;d++){
            bool ntight = tight && (d == num);
            bool nst = st || (d > 0);
            ans += rec(pos+1,ntight,nst,d,k);
        }

        return dp[tight][st][prev][pos] = ans;
    }

    ll goodIntegers(ll l, ll r, int k){

        nums = to_string(r);
        memset(dp,-1,sizeof(dp));
        ll sol = rec(0,1,0,0,k);

        l -= 1;
        nums = to_string(l);
        memset(dp,-1,sizeof(dp));
        sol -= rec(0,1,0,0,k);

        return sol;
    }
};