class Solution {
public:
    unordered_map<int,int> mp;
    int rec(int i){
        if(i == 0)
            return 0;

        if(i < 0)
            return INT_MAX;

        if(mp.find(i) != mp.end())
            return mp[i];

        int ans = INT_MAX;
        ans = min(ans,1 + (i % 2) + rec(i/2));
        ans = min(ans,1 + (i % 3) + rec((i/3)));
        
        return mp[i] = ans;
    }

    int minDays(int n) {
        mp.clear();
        return rec(n) - 1;
    }
};