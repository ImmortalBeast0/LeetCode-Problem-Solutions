class Solution {
    public int maxActiveSectionsAfterTrade(String a){
        char[] s = a.toCharArray();
        int n = s.length;

        int[] pre_one = new int[n];
        int cnt = 0;
        int[] pre = new int[n];
        pre[0] = -1;
        int idx = -1;
        for(int i=0;i<n;i++){
            pre[i] = idx;
            pre_one[i] = cnt;
            if(s[i] == '1'){
                idx = i;
                cnt += 1;
            }
            
        }

        int[] suf_one = new int[n];
        cnt = 0;
        int[] suf = new int[n];
        suf[n-1] = n;
        idx = n;
        for(int i=n-1;i>=0;i--){
            suf[i] = idx;
            suf_one[i] = cnt;
            if(s[i] == '1'){
                idx = i;
                cnt += 1;
            }
            
        }

        int sol = cnt;
        idx = -1;
        for(int i=0;i<n;i++){
            if(idx != -1 && s[i] == '0' && i - idx >= 2) 
                sol = Math.max(sol,suf[i] - pre[idx] - 1 + suf_one[i] + pre_one[idx]);

            if(s[i] == '0')
                idx = i;
        }

        // System.out.println(Arrays.toString(pre));
        // System.out.println(Arrays.toString(suf));
        // System.out.println(Arrays.toString(pre_one));
        // System.out.println(Arrays.toString(suf_one));
        return sol;
    }
}