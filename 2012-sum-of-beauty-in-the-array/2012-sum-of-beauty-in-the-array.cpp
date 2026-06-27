class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        
        int n = nums.size();
        int pre[n];
        int nxt[n];

        int mx = nums[0];
        for(int i=0;i<n;i++){
            pre[i] = mx;
            mx = max(mx,nums[i]);
        }

        mx = nums[n-1];
        for(int i=n-1;i>=0;i--){
            nxt[i] = mx;
            mx = min(mx,nums[i]);
        }


        int sol = 0;
        for(int i=1;i<n-1;i++){
            if(pre[i] < nums[i] && nxt[i] > nums[i]){
                sol += 2;
            }else if(nums[i-1] < nums[i] && nums[i+1] > nums[i])
                sol += 1;
        }

        return sol;
    }
};