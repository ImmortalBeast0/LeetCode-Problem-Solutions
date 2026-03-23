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

    vpi calc(vi& arr){
        int n = sz(arr);
        vpi xors;
        for(int mask=0;mask<(1 << n);mask++){
            int xo = 0;
            for(int i=0;i<n;i++){
                if(mask >> i & 1)
                    xo ^= arr[i];
            }
            xors.pb({xo,-__builtin_popcount(mask)});
        }

        return xors;
    }

    int minRemovals(vector<int>& nums, int target){

        int n = sz(nums);

        vi p1 ,p2;
        for(int i=0;i<n;i++){
            if(i % 2)
                p1.pb(nums[i]);
            else
                p2.pb(nums[i]);
        }
        
        vpi part1 = calc(p1);
        vpi part2 = calc(p2);

        sort(all(part1));
        sort(all(part2));

        int ans = n+1;
        for(auto p : part1){
            int a = p.F;
            int c = p.S;
            int key = target ^ p.F;
            auto id = lower_bound(all(part2),mp(key,-mod));
            if(id != part2.end() && id->F == key)
                ans = min(ans,n + c + id->S);
        }

        if(ans == n+1)
            ans = -1;

        return ans;
    }
};