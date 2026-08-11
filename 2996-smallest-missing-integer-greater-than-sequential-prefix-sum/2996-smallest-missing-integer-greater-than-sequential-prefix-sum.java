class Solution {
    public int missingInteger(int[] nums) {
        int sum = nums[0];
        int n = nums.length;
        HashMap<Integer,Boolean> mp = new HashMap<>();
        for(int i=0;i<n;i++)
            mp.put(nums[i],mp.getOrDefault(nums[i],true));

        
        for(int i=1;i<n;i++){
            if(nums[i-1] + 1 != nums[i])
                break;
            sum += nums[i];
        }

        while(mp.containsKey(sum))
            sum += 1;

        return sum;
    }
}