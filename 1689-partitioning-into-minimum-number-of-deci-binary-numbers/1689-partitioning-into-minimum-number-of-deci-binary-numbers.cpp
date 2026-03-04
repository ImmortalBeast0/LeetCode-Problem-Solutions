#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second

#define all(x) x.begin(), x.end()
#define sz(x) x.size()

#define mod (1e9) + 7
#define inf 1e9

using ll = long long;

class Solution {
public:
    int minPartitions(string n) {
        
        string ans = n;

        int sol = 0;
        while(true){
            bool flag = true;
            for(int i=0;i<ans.length();i++)
                if(ans[i] >= '1'){
                    ans[i] = ((ans[i] - '0' )- 1 )+ '0';
                    flag = false;
                }
            
            if(flag)
                break;
            sol += 1;
        }

        return sol;
    }
};