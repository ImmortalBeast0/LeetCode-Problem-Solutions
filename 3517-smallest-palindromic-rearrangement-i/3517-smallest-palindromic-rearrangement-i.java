class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();
        char[] str = s.toCharArray();
        TreeMap<Character,Integer> mp = new TreeMap<>();
        for(char c : str)
            mp.put(c,mp.getOrDefault(c,0)+1);

        Arrays.sort(str);
        char[] sol = new char[n];
        int k = 0;
        char odd = '#';
        for(char c : str)
            if(mp.get(c) % 2 == 1) odd = c;
        int i = 0 ,j = n - 1;
        while(i < j){
            if(mp.get(str[k]) % 2 == 1)
                odd = str[k];
            if(mp.get(str[k]) == 1){
                k++;continue;}
            mp.put(str[k],mp.get(str[k])-2);
            sol[i++] = str[k++];
            sol[j--] = str[k++];
        }
        
        if(n % 2 == 1)
            sol[i] = odd;

        return new String(sol);
    }
}