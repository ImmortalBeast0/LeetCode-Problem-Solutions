class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int n = s.length();

        int l = 0,r = 0;
        HashMap<Character,Integer> mp = new HashMap<>();

        int ans = 0;

        for(;r<n;r++){
            char c = s.charAt(r);
            mp.put(c,mp.getOrDefault(c,0)+1);

            while(mp.size() < (r - l + 1)){
                char d = s.charAt(l);
                mp.put(d,mp.get(d)-1);
                if(mp.get(d) == 0)
                    mp.remove(d);
                l += 1;
            }

            ans = Math.max(ans,r - l + 1);
        }

        return ans;
    }
}

/*

    for(l --> n){
        while(r --> n) try to expand with valid window

        atlast remove l from window
    }
    
    in this 
    for(r --> n){

        atFirst expand r 

        while(l < r) try to shrink with valid window
    }
*/