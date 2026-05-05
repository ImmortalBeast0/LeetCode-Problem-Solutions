class Solution {
public:
    long long countSubstrings(string s, char k) {
        long long ans = 0;
        long long cnt = 0;
        for(char c : s){
            if(k == c){
                cnt += 1;
                ans += cnt;
            }
        }
        return ans;
    }
};