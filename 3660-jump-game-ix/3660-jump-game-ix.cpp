class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol(n);
        sol[0] = nums[0];
        for(int i=1;i<n;i++)
            sol[i] = max(sol[i-1],nums[i]);

        int smn = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(smn < sol[i])
                sol[i] = max(sol[i],sol[i+1]);
            smn = min(smn,nums[i]);
        }

        return sol;
    }
};       