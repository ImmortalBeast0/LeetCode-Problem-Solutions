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
    int minSwaps(vii &grid){

        int n = sz(grid);
        int m = sz(grid[0]);
        vi cnt(n,0);

        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=m-1;j>=0;j--){
                if(grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            cnt[i] = count;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int req = m - i - 1;
            int j = i;

            while(j < n && cnt[j] < req){
                j += 1;
            }

            if(j >= n)
                return -1;

            while(j > i){
                swap(cnt[j],cnt[j-1]);
                j--;
                ans += 1;
            }
        }

        return ans;
    }
};