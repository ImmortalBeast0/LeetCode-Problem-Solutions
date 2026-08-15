class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length;
        int v = 0;
        int cnt = 0;
        for(int x : nums){
            cnt += (x == 0) ? 1 : 0;
            v ^= x;
        }
        // lets get the whole arr as subsequnce ,then arr{xor} != 0 ,arr length is solution 
        // else 
        // xor after cancellation ,xor value only made up by unique values into that ,making removing non zero make the arr length - 1 as valid non zero xor subsequnce and 

        //there all values is are zero ,nothing we do the every subsequce xor is zero then return zero;
        if(v != 0)
            return n;
        //
        
        if(cnt == n)
            return 0;

        return n - 1;
    }
}