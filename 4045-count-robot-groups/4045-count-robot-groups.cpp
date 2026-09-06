class Solution {
public:
    int countGroups(vector<int>& pos, vector<int>& s, int d) {
        int n = pos.size();
        int sol = 1;
        int ps = s[n-1];
        int pp = pos[n-1];
        for(int i=n-2;i>=0;i--){
            if(pos[i+1] - pos[i] <= d || s[i] - ps > 0)
                continue;
            else{
                sol += 1;
                pp = pos[i];
                ps = s[i];
            }
        }

        return sol;
    }
};