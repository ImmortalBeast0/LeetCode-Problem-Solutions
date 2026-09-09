class Solution {
    public long countCommas(long n) {
        long sol = 0;
        for(long i=(long)1e3;i<=(long)1e15;i *= (long)1e3){
            if(i > n)
                break;
            sol += n - i + 1;
        }   

        return sol;
    }
}