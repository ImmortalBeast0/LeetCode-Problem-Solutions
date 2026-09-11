class Solution {
    public int longestValidParentheses(String s) {
        Deque<Integer> st = new ArrayDeque<>();

        st.addLast(-1);
        int sol = 0;
        int i = 0;
        for(char c : s.toCharArray()){
            if(c == '(')
                st.addLast(i);
            else{
                st.pollLast();
                if(st.isEmpty())
                    st.addLast(i);
                else
                    sol = Math.max(sol,i - st.getLast());
            }
            i += 1;
        }

        return sol;
    }
}