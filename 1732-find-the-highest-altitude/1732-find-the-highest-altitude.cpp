class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int ans = 0;
        for(int x : gain){
            alt += x;
            ans = max(alt,ans);
        }
        return ans;
    }
};