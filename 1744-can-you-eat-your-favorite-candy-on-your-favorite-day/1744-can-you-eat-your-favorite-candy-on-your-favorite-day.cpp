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
#define mp make_pair
#define all(x) x.begin(),x.end()

class Solution {
public:
    using ll = long long;
    vector<bool> canEat(vector<int>& can, vector<vector<int>>& queries) {

        int n = can.size();

        vector<ll> ps(n+2);
        ps[0] = 0;
        for(int i=1;i<=n;i++)
            ps[i] = ps[i-1] + can[i-1];

        vector<bool> ans;
        
        for(vi q : queries){
            ll favType = q[0];
            ll favDay = q[1];
            ll cap = q[2];
            ll maxDay = ps[favType+1]-1;
            ll minDay = ps[favType]/cap;
            ans.push_back(favDay >= minDay && favDay <= maxDay);
        }
        
        return ans;
    }
};