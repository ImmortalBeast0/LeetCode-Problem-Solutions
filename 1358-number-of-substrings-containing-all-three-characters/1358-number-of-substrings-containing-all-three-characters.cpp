class Solution {
public:

    int cnt[3];
    bool check(){
        return cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1;
    }   
    void add(char c){
        cnt[c - 'a'] += 1;
    }
    void rem(char c){
        cnt[c - 'a'] -= 1;
    }
    int numberOfSubstrings(string s) {
        int n = s.length();
        int sol = 0;
        int l = 0;
        for(int r=0;r<n;r+=1){
            add(s[r]);
            while(check()){
                sol += (n - r);
                rem(s[l]);
                l += 1;
            }
        }

        return sol;
    }
};