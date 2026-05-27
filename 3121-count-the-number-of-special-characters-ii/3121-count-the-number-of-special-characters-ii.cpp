class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> lower(26,n+1) ,upper(26,-1);

        for(int i=0;i<n;i++){
            char c = word[i];
            if(c >= 'a' && c <= 'z'){
                lower[c - 'a'] = i;
            }else{ 
                if(upper[c - 'A'] == -1)
                    upper[c - 'A'] = i;
            }
        }
        

        int cnt = 0;
        for(int i=0;i<26;i++)
            cnt += (lower[i] < upper[i]);
        
        return cnt;
    }
};