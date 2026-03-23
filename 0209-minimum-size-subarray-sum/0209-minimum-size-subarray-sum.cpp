class Solution {
public:
    int summ;

    bool check(int k){
        return summ >= k;
    }

    void add(int x){
        summ += x;
    }

    void rem(int x){
        summ -= x;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        summ = 0;
        int n = nums.size() ,i = 0, j = -1 ,ans = n+1;
        for(;i<n;i++){
            while(j+1 < n && !check(target)){
                add(nums[j+1]);
                j += 1;
            }
            if(check(target))
                ans = min(ans,j - i + 1);
            rem(nums[i]);
        }
        if(ans == n+1)
            ans = 0;
        return ans;
    }
};