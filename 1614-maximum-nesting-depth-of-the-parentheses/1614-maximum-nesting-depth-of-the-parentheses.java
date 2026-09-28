class Solution {
    public int maxDepth(String s) {
        int op = 0;
        int ans = 0;
        int streak = 0;
        for(char c : s.toCharArray()){
            if(c == '('){
                if(streak > 0)
                    streak -= 1;
                op += 1;
            }
            if(c == ')'){
                if(op > 0){
                    streak += 1;
                    op -= 1;
                    ans = Math.max(ans,streak);
                }else
                    streak = 0;
            }
        }

        return ans;
    }
}