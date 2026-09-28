class Solution {
    public String reverseParentheses(String str) {
        char[] s = str.toCharArray();
        int n = s.length;

        Deque<Integer> st = new ArrayDeque<>();
        for(int i=0;i<n;i++){
            if(s[i] == '(')
                st.addFirst(i);
            if(s[i] == ')'){
                int l = st.pollFirst();
                revLR(l+1,i-1,s);
            }
        }

        StringBuffer sb = new StringBuffer("");
        for(char c : s){
            if(c != ')' && c != '(')
                sb.append(c);
        }

        return sb.toString();
    }
    void revLR(int l ,int r ,char[] s){
        while(l < r){
            char c = s[r];
            s[r] = s[l];
            s[l] = c;
            l += 1;r -= 1;
        }
    }
}