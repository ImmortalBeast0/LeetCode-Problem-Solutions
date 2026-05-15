// created by own understanding of first BS ok let try more

int findMin(int* nums, int numsSize) {
    int left = 0 , right = numsSize  -1 , mid ;
    while(left < right ){
        mid = left + ((right - left) / 2);
        if(nums[mid]<nums[right])
            right = mid ;
        else 
        left = mid + 1 ;
        
    }
    return nums[left];
}