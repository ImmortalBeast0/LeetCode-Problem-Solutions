class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        map<int,int> mp;

        int curSum = 0 ,ans = 0;

        mp[0] = 1;

        for(int r=0;r<n;r++){
            curSum += nums[r];
            if(mp.find(curSum - k) != mp.end()){
                ans += mp[curSum - k];
            }
            mp[curSum]++;
        }

        return ans;
    }
};