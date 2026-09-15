//--------------------------------------Lets Try Both Methods------------------------------------

class Manacher{
    int n;
    int[] p;
    char[] s;
    Manacher(String str){
        StringBuilder sb = new StringBuilder("");
        sb.append('#');
        for(char c : str.toCharArray()){
            sb.append(c).append('#');
        }
        s = sb.toString().toCharArray();
        n = s.length;
        p = new int[n];
        build();
    }

    void build(){
        Arrays.fill(p,1);
        int l = 1 ,r = 1;
        for(int j=1;j<n;j++){
            p[j] = 1;
            if(l + (r - j) >= 0)
                p[j] = Math.max(0,Math.min(r - j,p[l + (r - j)]));
            while(j - p[j] >= 0 && j + p[j] < n && s[j - p[j]] == s[j + p[j]])
                p[j] += 1;
            if(j + p[j] > r){
                r = j + p[j];
                l = j - p[j];
            }   
        }
    }

    int getLongestPalindrome(int idx ,int odd){
        int c = idx * 2 + 1;
        if(odd == 0)
            c += 1;
        return p[c] - 1;
    }

    boolean isPalindrome(int l ,int r){
        int len = (r - l + 1);
        return len <= (getLongestPalindrome((l + r)/2 ,len % 2));
    }
}

class Solution {

    boolean isPalindrome(int l ,int r ,char[] s){
        while(l < r && s[l] == s[r]){l++;r--;}
        return l >= r;
    }


    Manacher m;
    int dp[];
    int rec(int i ,int k ,char[] s){
        if(i < 0)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = (int)-1e9;

        ans = Math.max(ans,rec(i-1,k,s));

        for(int j=0;j<=i;j++){
            if(i - j + 1 >= k && isPalindrome(j,i,s))
                ans = Math.max(ans,rec(j-1,k,s)+1);
        }

        return dp[i] = ans;
    }

    public int maxPalindromes(String s, int k){
        m = new Manacher(s);
        dp = new int[s.length()+1];
        Arrays.fill(dp,-1);
        char[] str = s.toCharArray();
        return rec(s.length()-1,k,str);
    }
}