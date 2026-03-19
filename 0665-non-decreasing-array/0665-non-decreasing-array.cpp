#include<bits/stdc++.h>
using namespace std;

#define mod (int)1e9+7
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

class Solution {
public:
    bool checkPossibility(vector<int>& nums){
        int cnt = 0 ,i = 0;
        int n = sz(nums);

        while(i+1 < n){
            if(nums[i] > nums[i+1]){
                cnt+=1;
                if(cnt > 1) return false;

                if(i == 0 || (nums[i-1] <= nums[i+1]))
                    nums[i] = nums[i+1];
                else
                    nums[i+1] = nums[i];
            }
            i++;
        }

        return true;
    }
};
