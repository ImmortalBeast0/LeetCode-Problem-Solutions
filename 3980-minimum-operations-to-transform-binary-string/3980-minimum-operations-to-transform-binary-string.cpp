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

    int minOperations(string s1, string s2) {
        
        if(s1 == s2)
            return 0;

        int n = s1.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s1[i] == s2[i])
                continue;
            if(s1[i] == '0'){
                ans += 1;
                s1[i] = '1';
            }
            else if(i-1 >= 0 || i+1 < n){
                s1[i] = '0';
                if(i-1 >= 0 && !(i+1 < n)){
                    ans += 2;
                }else{
                    if(s1[i+1] == '1')
                        ans += 1;
                    else
                        ans += 2;
                    s1[i+1] = '0';
                }
            }
            else
                return -1;
        }

        return ans;
    }
};