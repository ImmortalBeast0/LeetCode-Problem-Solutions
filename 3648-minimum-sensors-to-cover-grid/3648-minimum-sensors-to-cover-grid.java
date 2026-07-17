class Solution {
    public int minSensors(int n, int m, int k) {
        int l = k + k + 1;
        return (int)(Math.ceil((double)n / l) * Math.ceil((double)m/l)); 
    }
}