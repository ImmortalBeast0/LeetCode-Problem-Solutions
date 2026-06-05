#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define ll long long

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

    ll dp[16][2][2][11][11][30];
    vi num;
    ll rec(int pos ,bool tight ,bool start ,int ld ,int lld ,int sum){
        if(pos >= num.size()){
            return sum;
        }

        if(dp[pos][tight][start][ld][lld][sum] != -1)
            return dp[pos][tight][start][ld][lld][sum];

        ll ans = 0;

        int lb = 0 ,ub = tight ? num[pos] : 9;
        for(int i=lb;i<=ub;i++){
            bool ntight = tight && (i == ub);
            bool nstart = start || (i > 0);

            if(nstart){
                int nsum = sum;
                if(ld != 10 && lld != 10){
                    nsum += (lld > ld) && (ld < i);
                    nsum += (lld < ld) && (ld > i);
                }
                ans += rec(pos+1,ntight,nstart,i,ld,nsum);
            }else{
                ans += rec(pos+1,ntight,nstart,ld,lld,sum);
            }
        }

        return dp[pos][tight][start][ld][lld][sum] = ans;
    
    }

    ll count(ll x){
        if(x == 0)
            return 0;
        num.clear();
        while(x){
            num.pb(x%10);
            x /= 10;
        }
        reverse(all(num));
        memset(dp,-1,sizeof(dp));
        return rec(0,1,0,10,10,0);
    }

    ll totalWaviness(ll num1, ll num2){
        return count(num2) - count(num1 - 1);
    }
};