class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int mx = nums[0];
        for(int x : nums)
            mx = Math.max(mx,x);

        int cnt = 0;
        while(mx > 0){
            cnt += 1;
            mx /= 2;
        }

        int mx_xor_range = (1 << cnt);
        boolean[] seen = new boolean[mx_xor_range + 1];

        for(int i=0;i<nums.length;i+=1){
            for(int j=i;j<nums.length;j+=1)
                seen[nums[i] ^ nums[j]] = true;
        }

        boolean[] sol = new boolean[mx_xor_range + 1];
        for(int i=0;i<=mx_xor_range;i++){
            if(seen[i]){
                for(int x : nums)
                    sol[x ^ i] = true;
            }
        }

        int ans = 0;
        for(boolean b : sol)
            ans += (b) ? 1 : 0;
    
        return ans;
    }
}