#include<bits/stdc++.h>
using namespace std;

#define mod ((ll)1e9+7)
#define ll long long

#define vi vector<ll>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back

#define F first

#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()

struct node{
    ll mx;
    node(){
        mx = -1e9;
    }
    node(ll x){
        mx = x;
    }
};

node merge(node a ,node b){
    node c = max(a.mx,b.mx);
    return c;
}

struct segtree{
    vector<node> tree;
    ll sz;

    void build(vector<ll>& nums){
        ll n = nums.size();
        sz = 1;
        while(sz <= n)
            sz *= 2;
        tree.resize(sz * 2);
        build(0,sz,0,nums);
    }
    void build(ll lb ,ll ub ,ll x ,vector<ll>& nums){
        if(ub - lb == 1){
            if(lb < nums.size())
                tree[x] = node(nums[lb]);
            return;
        }
        ll mi = (ub - lb)/2 + lb;
        build(lb,mi,x*2+1,nums);
        build(mi,ub,x*2+2,nums);
        tree[x] = merge(tree[x*2+1],tree[x*2+2]);
    }

    node rangeQurery(ll l ,ll r){
        return rangeQurery(0,sz,0,l,r+1);
    }
    node rangeQurery(ll lb ,ll ub ,ll x ,ll l ,ll r){
        if(lb >= r || ub <= l)
            return node();
        if(lb >= l && ub <= r)
            return tree[x];
        ll mi = (ub - lb)/2 + lb;
        node lt = rangeQurery(lb,mi,x*2+1,l,r);
        node rt = rangeQurery(mi,ub,x*2+2,l,r);
        return merge(lt,rt);
    }

    void pollUpdate(ll id ,ll val){
        pollUpdate(0,sz,0,id,val);
    }
    void pollUpdate(ll lb ,ll ub ,ll x ,ll id ,ll val){
        if(ub - lb == 1){
            tree[x] = node(val);
            return ;
        }
        ll mi = (ub - lb)/2 + lb;
        if(id < mi)
            pollUpdate(lb,mi,x*2+1,id,val);
        else
            pollUpdate(mi,ub,x*2+2,id,val);
        tree[x] = merge(tree[x*2+1],tree[x*2+2]);
    }
};

class Solution {
public:

    ll n ,k;

    ll maxAlternatingSum(vector<int>& arr, ll k_) {
        vector<ll> nums(all(arr));
        n = nums.size();
        k = k_;
        ll mx = *max_element(all(nums));
        vector<ll> a1(mx+1,-1e9);
        segtree seginc ,segdec;
        seginc.build(a1);
        segdec.build(a1);

        vector<vector<ll>> dp(n+1,vector<ll>(3));
        dp[0][0] = dp[0][1] = nums[0];

        for(ll i=1;i<n;i++){
            if(i-k >= 0){
                seginc.pollUpdate(nums[i-k], dp[i-k][0]);
                segdec.pollUpdate(nums[i-k], dp[i-k][1]);
            }
            dp[i][0] = dp[i][1] = nums[i];
            ll incmx = seginc.rangeQurery(nums[i]+1,mx).mx;
            ll  decmx = segdec.rangeQurery(0,nums[i]-1).mx;
            dp[i][0] = max(dp[i][0],nums[i]+decmx);
            dp[i][1] = max(dp[i][1],nums[i]+incmx);
        }

        ll bst = 0;
        for(ll i=0;i<n;i++){
            bst = max(bst,dp[i][0]);
            bst = max(bst,dp[i][1]);
        }

        return bst;
    }
};