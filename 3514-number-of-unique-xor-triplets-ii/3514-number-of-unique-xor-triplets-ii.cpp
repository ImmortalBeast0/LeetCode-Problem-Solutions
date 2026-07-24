class Solution {
public:

    bool dp[4][1501][2050];
    bool seen[2050];
    int cnt = 0;

    void rec(int i ,int len ,int zor ,vector<int>& nums){
        if(len == 3){
            if(!seen[zor]){
                seen[zor] = true;
                cnt += 1;
            }
            return;
        }
        if(i >= nums.size())
            return ;
        if(dp[len][i][zor])
            return ;
        rec(i+1,len,zor,nums);
        rec(i,len+1,zor^nums[i],nums);
        dp[len][i][zor] = true;
    }

    int uniqueXorTriplets(vector<int>& nums){
        rec(0,0,0,nums);
        return cnt;    
    }
};