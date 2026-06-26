#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9+7)


#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define F first
#define S second 
#define all(x) x.begin(),x.end()

class Solution {
public:
    ll sol = 0;
    vi ps;

    void merge(int l ,int mi ,int r){
        int i = l;
        int j = mi + 1;

        vi tmp;
        while(i <= mi && j <= r){
            if(ps[i] < ps[j]){
                tmp.pb(ps[i++]);
                sol += (r + 1 - j);
            }
            else{
                tmp.pb(ps[j++]);
            }
        }

        while(i <= mi)
            tmp.pb(ps[i++]);
        
        while(j <= r)
            tmp.pb(ps[j++]);

        for(int k=l;k<=r;k++){
            ps[k] = tmp[k-l];
        }
    }

    void merge_sort(int l ,int r){
        if(r - l + 1 > 1){
            int mi = (l+r)/2;
            merge_sort(l,mi);
            merge_sort(mi+1,r);
            merge(l,mi,r);
        }
    }

    ll countMajoritySubarrays(vi& nums ,int tar){

        int n = nums.size();
        ps.pb(0);

        int sum = 0;
        for(int &x : nums){
            sum += (x == tar) ? 1 : -1;
            ps.pb(sum);
        }

        merge_sort(0,n);

        return sol;
    }
};