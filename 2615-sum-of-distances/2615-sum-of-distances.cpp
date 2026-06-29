class Solution {
public:
    vector<long long> distance(vector<int>& nums){
        int n = nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<long long> sol(n,0);

        for(auto pi : mp){
            vector<int> arr = pi.second;
            if(arr.size() == 1)
                continue;
            long long val = 0;
            for(int i=1;i<arr.size();i++){
                val += (arr[i] - arr[0]);
            }
            sol[arr[0]] = val;
            for(int i=1;i<arr.size();i++){
                int diff = arr[i] - arr[i-1];
                sol[arr[i]] = sol[arr[i-1]] + diff * i  - (diff * (arr.size() - i));
            }
        }

        return sol;
    }
};