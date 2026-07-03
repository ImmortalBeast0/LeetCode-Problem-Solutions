//                  Counting Sort
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

    void countingSort(vector<int>& nums){
        int n = nums.size();

        int mx = *max_element(all(nums));
        int freq[mx+1];
        memset(freq,0,sizeof(freq));

        for(int x : nums)   // O(N)
            freq[x] += 1;

        for(int i=1;i<=mx;i++)      //O(Max(arr))
            freq[i] += freq[i-1];

        vector<int> arr(n);
        for(int i=n-1;i>=0;i--){
            int idx = --freq[nums[i]];
            arr[idx] = nums[i];
        }

        for(int i=0;i<n;i++)
            nums[i] = arr[i];
    }


    int maxIceCream(vector<int>& costs, int coins) {
        countingSort(costs);

        int sol = 0;
        for(int i=0;i<costs.size();i++){
            if(coins < costs[i])
                break;
            coins -= costs[i];
            sol += 1;
        }

        return sol;
    }
};