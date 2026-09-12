#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9+7)
#define vi vector<ll>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define F first
#define S second
#define pb push_back
#define bp pop_back
#define all(x) x.begin(),x.end()

class Solution {
public:
    int n;
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        n = nums.size();
        ll x = two_pointer(nums,(ll)k + (ll)goal - 1) - two_pointer(nums,(ll)goal - (ll)k);
        if(k <= 0)
            x = 0;
        return ((ll)n * (ll)(n+1))/ 2 - x;
    }

    ll two_pointer(vector<int> nums , ll tar){

        vi ps(n+1,0);
        for(int i=0;i<n;i++)
            ps[i+1] = ps[i] + nums[i];

        return merge_sort(ps,0,n,tar);
    }

    ll merge(vi& nums ,int lb ,int mi ,int ub,ll x){

        ll cnt = 0;
        int i = lb;
        for(int j = mi + 1; j <= ub; j++) {
            while (i <= mi && nums[j] - nums[i] > x) {
                i++;
            }
            cnt += (mi - i + 1);
        }

        vi tmp;
        i = lb;int j = mi + 1;
        while(i <= mi && j <= ub){
            if(nums[i] < nums[j])
                tmp.pb(nums[i++]);
            else
                tmp.pb(nums[j++]);
        }

        while(i <= mi)
            tmp.pb(nums[i++]);
    
        while(j <= ub)
            tmp.pb(nums[j++]);
    
        for(int k=lb;k<=ub;k++)
            nums[k] = tmp[k - lb];

        return cnt;
    }

    ll merge_sort(vi& nums ,int lb ,int ub ,ll x){
        ll cnt = 0;
        if(ub - lb >= 1){
            int mi = (ub - lb)/2 + lb;
            cnt += merge_sort(nums,lb,mi,x);
            cnt += merge_sort(nums,mi+1,ub,x);
            cnt += merge(nums,lb,mi,ub,x);
        }
        return cnt;
    }
};