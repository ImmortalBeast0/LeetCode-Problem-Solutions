#define pb push_back
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr;
        for(int x : nums)
            if(x < pivot)
                arr.pb(x);
        for(int x : nums)
            if(x == pivot)
                arr.pb(x);
        for(int x : nums)
            if(x > pivot)
                arr.pb(x);
        return arr;
    }
};