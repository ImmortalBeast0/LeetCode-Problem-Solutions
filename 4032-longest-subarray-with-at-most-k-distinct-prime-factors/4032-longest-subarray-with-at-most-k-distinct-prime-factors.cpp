#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define F first
#define S second
#define pb push_back
#define bp pop_back
#define all(x) x.begin(),x.end()

bool flag = true;
    vector<pair<bool,vector<int>>> pf;
    void seive(){
        flag = false;
        int n = 1e5 + 1;
        pf.resize(n + 5);
        for(int i=0;i<=n;i++){
            pf[i].F = true;
        }

        pf[0].F = pf[1].F = false;
        for(int i=2;i<=n;i++){
            if(pf[i].F){
                pf[i].S.pb(i);
                for(int j=i+i;j<=n;j+=i){
                    pf[j].F = false;
                    pf[j].S.pb(i);
                }
            }
        }
    }

class Solution {
public:

    int longestSubarray(vector<int>& nums, int k) {
        if(flag)
            seive();

        int n = nums.size();
        int i = 0 ,j = 0;
        int sol = 0;
        map<int,int> mp; 
        for(;j<n;j++){
            add(mp,nums[j]);
            while(mp.size() > k && i < j)
                rem(mp,nums[i++]);
            if(mp.size() <= k)
                sol = max(sol,j - i + 1);
        }

        return sol;
    }

    void add(map<int,int>& mp ,int x){
        for(int v : pf[x].S)
            mp[v] += 1;
    }

    void rem(map<int,int>& mp ,int x){
        for(int v : pf[x].S){
            mp[v] -= 1;
            if(mp[v] == 0)
                mp.erase(v);
        }
    }
};