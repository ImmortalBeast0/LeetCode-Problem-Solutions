#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod ((int)1e9+7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>
#define pb push_back
#define bp pop_back
#define F first
#define S second
#define all(x) x.begin(),x.end()

class Solution {
public:

    int n;

    pi merge(pi a ,pi b ,int peak ,int op){
        b.F += peak;
        b.S += op;
        if(a.F > b.F)
            return a;
        else if(a.F == b.F)
            return {a.F,min(a.S,b.S)};
        else
            return b;
    }

    bool done[(int)1e5+5];
    pi dp[(int)1e5+5];

    pi rec(int i,vi& nums){
        if(i >= n-1){
            return {0,0};
        }

        if(done[i])
            return dp[i];

        pi ans = {0,1e9};
        ans = merge(ans,rec(i+1,nums),0,0);
        if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
            ans = merge(ans,rec(i+2,nums),1,0);
        }else{
            int op = max(nums[i-1],nums[i+1]) - nums[i] + 1;
            ans = merge(ans,rec(i+2,nums),1,op);
        }

        done[i] = true;
        dp[i] = ans;
        return ans;
    }   

    ll minIncrease(vi& nums) {
       n = nums.size();
       return rec(1,nums).S; 
    }
};
