class Solution {
    public int maxSumRangeQuery(int[] nums, int[][] requests){
        
        int n = nums.length;
        int m = requests.length;
        final int mod = (int)1e9 + 7;

        int[] cnt = new int[n];

        for(int i=0;i<m;i++){
            int l = requests[i][0];
            int r = requests[i][1];
            cnt[l] += 1;
            if(r + 1 < n)
                cnt[r + 1] -= 1;
        }

        for(int i=1;i<n;i++)
            cnt[i] += cnt[i-1];

        Arrays.sort(nums);
        Arrays.sort(cnt);

        int sol = 0;
        for(int i=n-1;i>=0;i--)
            if(cnt[i] > 0)
                sol = (int)(sol + ((long)nums[i] * cnt[i]) % mod ) % mod;

        return sol;
    }
}