class Solution {
    public int minAddToMakeValid(String s) {
        int sol = 0;
        int op = 0;
        for(char c : s.toCharArray()){
            if(c == '(')
                op += 1;
            else{
                if(op - 1 < 0)
                    sol += 1;
                else 
                    op -= 1;
            }
        }

        return sol + op;
    }
}