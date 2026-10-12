class Solution {
    public int resilientSubarray(int[] nums, int k) {
        int n = nums.length;

        for(int i = 0; i < n; i += 1)
            nums[i] %= k;

        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();

        long summ = 0;
        int l = 0, ans = 0;
        for(int r = 0; r < n; r += 1){
            mp.put(nums[r], mp.getOrDefault(nums[r], 0) + 1);
            summ += nums[r];

            while(l <= r && mp.size() > 1){
                int oldFreq = mp.get(nums[l]);
                oldFreq -= 1;

                mp.remove(nums[l]);
                if(oldFreq > 0)
                    mp.put(nums[l], oldFreq);

                summ -= nums[l];

                l += 1;
            }

            long rhs = summ / (r - l + 1);
            if(summ % k == rhs)
                ans = Math.max(ans, r - l + 1);
        }

        return ans;
    }   
}