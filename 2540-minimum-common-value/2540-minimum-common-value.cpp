class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int x : nums1)
            mp[x]++;
        sort(nums2.begin(),nums2.end());
        for(int x : nums2){
            if(mp.find(x) != mp.end())
                return x;
        }

        return -1;
    }
};