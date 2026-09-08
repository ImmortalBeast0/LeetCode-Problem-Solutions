class Solution {
    public int countCommas(int n) {  
        int sol = 0;
        if(n - 999 > 0)
            sol += n - 999;
        return sol;
    }
}