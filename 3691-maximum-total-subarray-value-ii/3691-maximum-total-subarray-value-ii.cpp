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



#define F first
#define S second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()

class Solution {
public:

    static const int K = 25;
    vector<vpi> st;

    pi merge(pi& a ,pi& b){
        return {max(a.F,b.F),min(a.S,b.S)};
    }

    void build(int n ,vi& nums){

        st.resize(K+1,vpi(n+1));

        for(int j=0;j<n;j++)
            st[0][j] = {nums[j],nums[j]};

        for(int i=1;i<=K;i++){
            for(int j=0;j + (1 << (i-1)) <= n;j++){
                st[i][j] = merge(st[i-1][j],st[i-1][j + (1 << (i - 1))]);
            }
        }
    }

    pi rangeQuery(int l ,int r){
        pi sol = {-1e18,1e18};
        for(int i=K;i>=0;i--){
            if(r - l + 1 >= (1 << i)){
                sol = merge(sol,st[i][l]);
                l += (1 << i);
            }
        }

        return sol;
    } 

    ll maxTotalValue(vi& nums, int k) {

        int n = nums.size();
        build(n,nums);
        priority_queue<pair<ll,pair<int,int>>> pq;

        for(int l=0;l<n;l++){
            pi p = rangeQuery(l,n-1);
            ll val = p.F - p.S;
            pq.push({val,{l,n-1}});
        }

        ll sol = 0;
        while(k--){
            pi range = pq.top().S;
            ll val = pq.top().F;
            pq.pop();
            sol += val;

            int l = range.F;
            int r = range.S; 
            if(r-1 >= l){
                pi p = rangeQuery(l,r-1);
                ll val = p.F - p.S;
                pq.push({val,{l,r-1}});
            }
        }

        return sol;
    }
};