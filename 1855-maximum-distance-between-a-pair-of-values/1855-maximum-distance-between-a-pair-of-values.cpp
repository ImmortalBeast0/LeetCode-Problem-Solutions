class Solution {
public:
    int n,m;
    int get(int key ,vector<int>& nums){
        int ans = m+1;
        int lb = 0,ub = n-1,mi;
        while(lb <= ub){
            mi = (ub - lb)/2 + lb;
            if(nums[mi] <= key){
                ub = mi - 1;
                ans = mi;
            }else
                lb = mi + 1;
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2){
        n = nums1.size();
        m = nums2.size();
        int sol = 0;
        for(int j=m-1;j>=0;j--){
            int i = get(nums2[j],nums1);
            sol = max(sol,max(j - i,0));
        }

        return sol;
    }
};