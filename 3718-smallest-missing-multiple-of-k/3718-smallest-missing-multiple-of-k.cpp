class Solution {
public:

    int bs(vector<int>& nums ,int key){
        int n = nums.size();
        int lb = 0 ,ub = n-1;
        while(lb <= ub){
            int mid = (lb+ub)/2;
            if(nums[mid] == key)
                return mid;
            else if(nums[mid] > key)
                ub = mid - 1;
            else
                lb = mid + 1;
        }

        return -1;
    }
    
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<=1000;i++){
            if(bs(nums,k*i) == -1)
                return k * i;
        }

        return -1;
    }
};