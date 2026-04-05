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
    vector<string> sols;
    string sol;
    int rec(int i ,int op ,string& s){
        if(i == n){
            if(op == 0){
                sols.pb(sol);
                return 0;
            }
            return -1e9;
        }

        if(op < 0 || op > (n/2))
            return -1e9;

        int ans = -1e9;
        ans = max(ans,rec(i+1,op,s));
        sol.pb(s[i]);
        if(s[i] == ')' || s[i] == '(')
            ans = max(ans,rec(i+1,op + (s[i] == '(' ? 1 : -1),s) + 1);
        else
            ans = max(ans,rec(i+1,op,s)+1);
        sol.bp();

        return ans;
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        int len = rec(0,0,s);
        set<string> ans;
        for(string x : sols)
            if(x.length() == len)
                ans.insert(x);

        return vector<string>(all(ans));
    }
};