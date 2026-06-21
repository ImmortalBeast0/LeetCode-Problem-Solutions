#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>

#define F first
#define S second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int arr[(int)1e5+1];
        memset(arr,0,sizeof(arr));
        for(int x : costs)
            arr[x]++;
        costs.clear();
        for(int i=0;i<=1e5;i++){
            for(int j=0;j<arr[i];j++)
                costs.push_back(i);
        }
        int ans = 0;
        int used = 0;
        for(int x : costs){
            cout << x << ' ';
            if(used + x <= coins){
                ans += 1;
                used += x;
            }else
                break;
        }

        return ans;
    }
};