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
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

ll const N = 100005;
bool flag = true;
ll fact[N];

void calc(){
    flag = false;
    fact[0] = 1;
    for(ll i=1;i<N;i++)
        fact[i] = (fact[i-1] * i) % mod;
}

ll binExp(ll a ,ll b){

    ll ans = 1;

    while(b){
        if(b & 1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }

    return ans;
}

ll modInv(ll a){
    return binExp(a,mod-2);
}

class Solution {
public:
    int countVisiblePeople(int n, int pos, int k) {
        
        if(flag)
            calc();

        ll sol = 2;
        sol *= fact[n-1];
        sol %= mod;
        sol *= modInv(fact[n-1-k]);
        sol %= mod;
        sol *= modInv(fact[k]);
        sol %= mod;

        return sol;
    }
};
