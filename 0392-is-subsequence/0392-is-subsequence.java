class Solution {
    public boolean isSubsequence(String str, String ttr) {
        char[] s = str.toCharArray();
        char[] t = ttr.toCharArray();
        int n = s.length ,m = t.length;
        int i = 0 , j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                i += 1;
                j += 1;
            }else
                j += 1;
        }

        return i >= n;
    }
}