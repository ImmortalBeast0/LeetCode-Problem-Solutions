/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int n, int target, int* returnSize){
    
    int* ans = (int*)malloc(2 * sizeof(int));
    // int n = sizeof(nums) / sizeof(nums[0]);
    *returnSize = 2;
    printf("%d",n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i] + nums[j] == target){
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }

    return ans;
}