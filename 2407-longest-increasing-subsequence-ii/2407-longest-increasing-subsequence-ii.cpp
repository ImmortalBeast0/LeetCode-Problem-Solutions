#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
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

struct node{
	ll maxx;
	node(){
        maxx = -1e9;
	}
	node(int x){
		maxx = x;
	}
};

node merge(node a ,node b){
	node c = max(a.maxx,b.maxx);
	return c;
}

struct segtree{

	ll sz;
	vector<node> tree;
	vector<ll> lazy;

	void build(vi& nums){
		int n = nums.size();
		sz = 1;
		while(sz <= n){
			sz *= 2;
		}

		tree.resize(sz * 2);
		lazy.resize(sz * 2);
		build(0,sz,0,nums);
	}

	void build(int lb ,int ub ,int x ,vi& nums){
		if(ub - lb == 1){
			if(lb < nums.size())
				tree[x] = node(nums[lb]);
			return ;
		}
		int mi = (ub - lb)/2 + lb;
		build(lb,mi,x*2+1,nums);
		build(mi,ub,x*2+2,nums);
		tree[x] = merge(tree[x*2+1],tree[x*2+2]);
	}

	void push(int lb ,int ub ,int x ,int val){
		tree[x].maxx += val;
		if(ub - lb != 1){
			lazy[x * 2 + 1] += val;
			lazy[x * 2 + 2] += val;
		}
		lazy[x] = 0;
	}

	node getRange(int l ,int r){
		return getRange(0,sz,0,l,r+1);
	}

	node getRange(int lb ,int ub ,int x ,int l ,int r){
		if(lazy[x] != 0)
			push(lb,ub,x,lazy[x]);

		if(lb >= r || ub <= l)
			return node();

		if(lb >= l && ub <= r)
			return tree[x];

		int mi = (ub - lb)/2 + lb;
		return merge(getRange(lb,mi,x*2+1,l,r),getRange(mi,ub,x*2+2,l,r));
	}

    void pointUpdate(int pos ,int val){
        pointUpdate(0,sz,0,pos,val);
    }

    void pointUpdate(int lb ,int ub ,int x ,int pos ,int val){
        if(lazy[x] != 0)
            push(lb,ub,x,lazy[x]);

        if(ub - lb == 1){
            tree[x] = node(val);
            return ;
        }
        
        int mi = (ub - lb)/2 + lb;
        if(pos < mi)
            pointUpdate(lb,mi,x*2+1,pos,val);
        else
            pointUpdate(mi,ub,x*2+2,pos,val);
        tree[x] = merge(tree[x*2+1],tree[x*2+2]);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        
        int n = nums.size();
        int mx = *max_element(all(nums));
        vector<int> arr(2 * mx,-1e9);
        segtree sg;
        sg.build(arr);

        int dp[n];
        dp[0] = 1;
        sg.pointUpdate(nums[0],1);
        for(int i=1;i<n;i++){
            dp[i] = 1;
            int ans = sg.getRange(nums[i] - k ,nums[i]-1).maxx;
            dp[i] = max(dp[i],1 + ans);
            sg.pointUpdate(nums[i],dp[i]);
        }

        return *max_element(dp,dp+n);
    }
};