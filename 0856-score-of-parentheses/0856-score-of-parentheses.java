class Solution {
    public int scoreOfParentheses(String str){

        char[] s = str.toCharArray();
        int n = s.length;

        int[] idx = new int[n];
        int[] sc = new int[n];

        Deque<Integer> st = new ArrayDeque<>();

        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                int id = st.pollFirst();
                if(i - id == 1){
                    sc[id] = 1;
                }else{
                    int sum = 0;
                    for(int j=id+1;j<=i;j++){
                        sum += sc[j];
                        sc[j] = 0;
                    }
                    sc[id] = sum * 2;
                }
            }else{
                st.addFirst(i);
            }
        }

        int ans = 0;
        for(int x : sc)
            ans += x;

        return ans;
    }
}