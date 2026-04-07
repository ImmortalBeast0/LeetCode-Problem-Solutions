#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (int)1e9
#define N 100001 
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define F first
#define S second 

#define pb push_back
#define bp pop_back
#define mp make_pair

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

class Solution {
public: 

    int n;
    int dp[50005];
    int rec(int i ,vi& endTime ,vi& startTime ,vi& profit){
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = -inf;
        int en = endTime[i];
        int idx = (lower_bound(startTime.begin(),startTime.end(),en) - startTime.begin());
        ans = max(ans,profit[i] + rec(idx,endTime,startTime,profit));
        ans = max(ans,rec(i+1,endTime,startTime,profit));

        return dp[i] = ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<vector<int>> events;
        n = startTime.size();

        for(int i=0;i<n;i++)  
                events.pb({startTime[i],endTime[i],profit[i]});

        sort(all(events));
        startTime.clear();
        endTime.clear();
        profit.clear();
        for(auto arr : events){
            startTime.pb(arr[0]);
            endTime.pb(arr[1]);
            profit.pb(arr[2]);
        }
        
        memset(dp,-1,sizeof(dp));
        return rec(0,endTime,startTime,profit);
    }
};