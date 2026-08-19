class Solution {
    int minOperations(String s) {
        
        char[] str = s.toCharArray();
        int sol = getOperations(str);
        for(int i=1;i<str.length;i++){
            rotate(str);
            sol = Math.min(sol,getOperations(str) + i);
        }

        return sol;
    }

    void rotate(char[] s){
        char x = s[0];
        for(int i=1;i<s.length;i++)
            s[i-1] = s[i];
        s[s.length-1] = x;
    }

    int getOperations(char[] s){
        int op = 0;
        int n = s.length;
        int i = n / 2 - (( n % 2 == 0) ? 1 : 0);
        int j = n / 2 ;
        for(;i>=0&&j<n;i--,j++){
            int x = s[i] - 'a';
            int y = s[j] - 'a';
            int mn = Math.min(x,y);
            int mx = Math.max(x,y);
            op += Math.min(mx - mn,26 - mx + mn);
        }

        return op;
    }



};