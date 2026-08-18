class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> set = new HashSet<Integer>();
        for(int x : nums)
            set.add(x);

        int sol = 0; // longest sequence 
        for(int x : set){
            if(!set.contains(x - 1)){
                int cur = x + 1;
                int len = 1;
                while(set.contains(cur)){
                    cur += 1;
                    len += 1;
                }

                sol = Math.max(sol,len);
            }
        }

        return sol;
    }
}