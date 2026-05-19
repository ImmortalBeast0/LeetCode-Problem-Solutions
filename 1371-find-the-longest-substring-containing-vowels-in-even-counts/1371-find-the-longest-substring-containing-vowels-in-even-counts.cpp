class Solution {
public:
    using ll = long long;
    bool check(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int findTheLongestSubstring(string s) {
        
        int n = s.length();
        vector<ll> nums;
        for(char c : s){
            if(check(c))
                nums.push_back(1 << (c - 'a'));
            else
                nums.push_back(0);
        }

        unordered_map<ll,int> mp;
        mp[0] = -1;
        ll cur_xor = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            cur_xor ^= nums[r];
            if(mp.find(cur_xor) != mp.end()){
                int l = mp[cur_xor];
                ans = max(ans, r - l);
            }else{
                mp[cur_xor] = r;
            }
        }

        return ans;
    }
};
r -l + 2