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

    int n;

    bool check(ll minn ,vector<ll>& stat ,int r ,int k){

        ll need = 0;

        vector<ll> partial(n,0);

        for(int i=0;i<n;i++){
            if(i-1 >= 0)    partial[i] += partial[i-1];
            if(stat[i] + partial[i] < minn){
                ll req = minn - (stat[i] + partial[i]);
                partial[i] += req;
                need += req;
                if(i+r+r+1 < n)
                    partial[i+r+r+1] -= req;
            }
            if(need > k)
                return false;
        }

        return need <= k;
    }

    ll maxPower(vi& st, int r, int k){
        

        vector<ll> sta(all(st));
        n = sta.size(); 

        vector<ll> partial(n,0);

        for(int i=0;i<n;i++){
            int start = max(0,i-r);
            int end = min(n-1,(i+r));
            partial[start] += sta[i];
            if(end + 1 < n)
                partial[end+1] -= sta[i];
        }

        for(int i=1;i<n;i++)
            partial[i] += partial[i-1];

        for(int i=0;i<n;i++){
            sta[i] = partial[i];
        }

        ll lb = *min_element(sta.begin(),sta.end());
        ll ub = (accumulate(all(sta),0ll) + (ll)k * (2*r + 1)) / n;
        ll ans = lb;

        while(lb <= ub){
            ll mi = (ub - lb)/2 + lb;
            if(check(mi,sta,r,k)){
                ans = mi;
                lb = mi + 1;
            }else
                ub = mi  - 1;
        }

        return ans;
    }
};