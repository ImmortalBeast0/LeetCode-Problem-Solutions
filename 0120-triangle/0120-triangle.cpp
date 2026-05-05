class Solution {
public:
    int n;
    int dp[232][232];
    bool flag[232][232];
    int rec(int i ,int j ,vector<vector<int>>& tri){
        if(i == n-1){
            return tri[i][j];
        }
        if(flag[i][j])
            return dp[i][j];

        int ans = 1e9;
        ans = min(ans,rec(i+1,j,tri)+tri[i][j]);
        if(j+1 < tri[i+1].size())
            ans = min(ans,rec(i+1,j+1,tri)+tri[i][j]);

        flag[i][j] = 1;
        return dp[i][j] = ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        return rec(0,0,triangle);
    }
};