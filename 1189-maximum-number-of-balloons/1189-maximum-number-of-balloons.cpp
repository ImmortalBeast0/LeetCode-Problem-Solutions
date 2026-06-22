class Solution {
public:
    int maxNumberOfBalloons(string text) {
        set<char> ss = {'b','a','l','o','n'};
        unordered_map<char,int> mp;
        for(char c : text){
            if(ss.find(c) != ss.end())
                mp[c]++;
        }
        int mn = text.length();
        for(auto x : ss){
            int f = mp[x];
            if(x == 'l' || x == 'o')
                f /= 2;
            mn = min(f,mn);
        }
        return mn;

    }
};