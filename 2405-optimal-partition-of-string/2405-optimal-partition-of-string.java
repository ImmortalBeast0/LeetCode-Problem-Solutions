class Solution {
    public int partitionString(String s) {

        int n = s.length();
        HashMap<Character,Integer> mp = new HashMap<>();
        int r = 0 ,ans = 0;
        
        while(r < n){
            int l = r;
            while(l < n && mp.getOrDefault(s.charAt(l),0) == 0){
                mp.put(s.charAt(l),1);
                l += 1;
            }
            ans += 1;
            while(r < n && mp.get(s.charAt(r)) == 1){
                mp.put(s.charAt(r),0);
                r += 1;
            }
        }

        return  ans;
    }
}