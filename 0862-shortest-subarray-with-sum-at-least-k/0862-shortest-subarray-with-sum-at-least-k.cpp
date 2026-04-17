#include<bits/stdc++.h>
using namespace std;

#define mod ((ll)1e9+7)
#define ll long long

#define vi vector<ll>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k){     

        int n = nums.size();
        vi ps(n+1,0);
        ps[0] = nums[0];
        for(int i=0;i<n;i++)
            ps[i+1] = ps[i] + nums[i]; 

        deque<int> dq;
        int sol = n+1;
        for(int i=0;i<=n;i++){
            while(!dq.empty() && ps[i] - ps[dq.front()] >= k){
                sol = min(sol,(i - dq.front()));
                dq.pop_front();
            }
            while(!dq.empty() && ps[dq.back()] >= ps[i])
                dq.pop_back();
            dq.push_back(i);
        }

        if(sol == n+1)
            sol = -1;
        return sol;
    }
};