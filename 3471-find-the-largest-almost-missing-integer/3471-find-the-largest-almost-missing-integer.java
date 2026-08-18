class Solution {
    public int largestInteger(int[] nums, int k) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        if(nums.length==k){
            int res=nums[0];
            for(int i:nums){
                res=Math.max(res,i);
            }
            return res;
        }
        
        for(int x : nums){
            mp.put(x,mp.getOrDefault(x,0) + 1);
        }
        
        if(k == 1){
            int mx = -1;
            for(int x : nums){
                if(mp.get(x) == 1)
                    mx = Math.max(mx,x);
            }
            return mx;
        }

        int ans = -1;
        if(mp.get(nums[0]) == 1)
            ans = Math.max(ans,nums[0]);

        if(mp.get(nums[nums.length - 1]) == 1)
            ans = Math.max(ans,nums[nums.length - 1]);

        return ans;
    }
}