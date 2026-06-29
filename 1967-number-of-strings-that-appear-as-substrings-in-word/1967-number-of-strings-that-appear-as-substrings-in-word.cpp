class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int sol = 0;
        for(string x : patterns)
            sol += (word.find(x) != string::npos);

        return sol;
    }
};