#include<bits/stdc++.h>
using namespace std;

#define mod (int)1e9+7
#define ll long long

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
#define sz(x) x.size()

class Solution {
public:
    string mergeCharacters(string s, int k) {
        
        int n = s.length();

        vector<int> mpp(27,-1);
        string ans = "";
        ans += s[0];
        mpp[s[0] - 'a'] = 0;
        int cnt = 0;
        for(int i=1;i<n;i++){
            char c = s[i];
            if(mpp[c-'a'] != -1 && i - mpp[c - 'a'] - cnt<= k){
                cnt++;
                continue;
            }
            mpp[c - 'a'] = i - cnt;
            ans += c;
        }

        return ans;
    }
};
