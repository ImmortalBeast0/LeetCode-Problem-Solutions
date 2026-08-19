class Solution {
    public int maximumGap(String skill, String station) {
        char[] s = skill.toCharArray();
        char[] t = station.toCharArray();

        int n = s.length;
        int m = t.length;

        int[] earliest = new int[n];
        for(int i=0,j=0;i<n&&j<m;j++){
            if(s[i] == t[j]){
                earliest[i] = j;
                i += 1;
            }
        }

        int[] latest = new int[n];
        for(int i=n-1,j=m-1;i>=0&&j>=0;j--){
            if(s[i] == t[j]){
                latest[i] = j;
                i -= 1;
            }
        }

        int sol = 0;
        for(int i=0;i<n-1;i++)
            sol = Math.max(sol,latest[i + 1] - earliest[i]);
        
        return sol;
    }
}