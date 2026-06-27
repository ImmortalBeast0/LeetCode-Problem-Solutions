class Solution {
public:
    int maximumLength(vector<int>& nums){

        int n = nums.size();
        unordered_map<long long,int> mp;
        for(int x : nums)
            mp[x] += 1;

        int sol = 0;
        if(mp[1] % 2 == 1){
            sol = mp[1];
        }else
            sol = mp[1] - 1;

        mp.erase(1);

        for(auto p : mp){
            int len = 0;
            long long x = p.first;
            while(mp.contains(x) && mp[x] > 1){
                len += 2;
                x *= x;
            }

            if(mp.contains(x))
                len += 1;
            else
                len -= 1;

            sol = max(sol,len);
        }

        return sol;
    }   
};