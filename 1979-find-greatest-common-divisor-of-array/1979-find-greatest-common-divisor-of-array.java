class Solution {
    int gcd(int a ,int b){
        if(b == 0)
            return a;
        return gcd(b,a % b);
    }
    public int findGCD(int[] nums) {
        int mn = nums[0];
        int mx = nums[0];
        for(int x  : nums){
            mn = Math.min(mn,x);
            mx = Math.max(mx,x);
        }
        return gcd(mn,mx);
    }
}