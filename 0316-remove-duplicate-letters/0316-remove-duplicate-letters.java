class Solution {
    public String removeDuplicateLetters(String s) {
        
        int[] cnt = new int[26];
        boolean[] vis = new boolean[26];
        char[] str = s.toCharArray();

        for(char c : str)
            cnt[c - 'a'] += 1;

        Deque<Character> st = new ArrayDeque<>();
        for(char c : str){
            cnt[c - 'a'] -= 1;
            if(vis[c - 'a'])
                continue;

            while(!st.isEmpty() && st.peek() > c && cnt[st.peek() - 'a'] > 0)
                vis[st.poll() - 'a'] = false;
            
            st.push(c);
            vis[c - 'a'] = true;
        }

        StringBuilder sb = new StringBuilder();
        while(!st.isEmpty())
            sb.append(st.poll());

        return sb.reverse().toString();
    }
}