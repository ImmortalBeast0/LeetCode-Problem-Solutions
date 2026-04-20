class Solution {
public:
    int n,m;

    int get(int key ,vector<int>& nums){
        int ans = m+1;
        int lb = 0,ub = n-1;
        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            if(nums[mi] <= key){
                ub = mi - 1;
                ans = mi;
            }else{
                lb = mi + 1;
            }
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2){
        n = nums1.size();
        m = nums2.size();
        int sol = 0;
        for(int i=m-1;i>=0;i--){
            int rt = nums2[i];
            int idx = get(rt,nums1);
            if(idx <= i)
                sol = max(sol,i - idx);
        }

        return sol;
    }
};