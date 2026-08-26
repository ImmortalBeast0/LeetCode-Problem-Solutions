class Solution {
    public String shortestBeautifulSubstring(String str, int k) {
        char[] s = str.toCharArray();
        int n = s.length;
        for(int i=1;i<=n;i++){
            boolean flag = false;
            String ans = null;
            int sum = 0;
            for(int j=0;j<i;j++)
                sum += (s[j] == '1') ? 1 : 0;

            if(sum == k){
                flag = true;
                String t = str.substring(0,i);
                if(ans == null || ans.compareTo(t) > 0)
                    ans = t;
            }

            for(int j=i;j<n;j++){
                sum += (s[j] == '1') ? 1 : 0;
                sum -= (s[j - i] == '1') ? 1 : 0;
                if(sum == k){
                    flag = true;
                    String t = str.substring(j-i+1,j+1);
                    if(ans == null || ans.compareTo(t) > 0)
                        ans = t;
                }  
            }

            if(flag)
                    return ans;
        }

        return "";
    }
}