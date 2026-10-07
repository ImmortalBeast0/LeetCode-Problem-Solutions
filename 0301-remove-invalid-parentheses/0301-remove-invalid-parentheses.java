class Solution {
    Set<String> sets;
    void rec(int i ,int cnt ,StringBuffer str ,char[] s ,int invalids ,int op){

        if(i >= s.length){
            if(cnt == invalids && op == 0)
                sets.add(str.toString());
            return ;
        }

        if(cnt > invalids)
            return ;
        
        boolean f = true;
        if(s[i] == ')' && op - 1 < 0)
            f = false;
        if(f){
            str.append(s[i]);
            rec(i+1,cnt,str,s,invalids,op + (s[i] == '(' ? 1 : (s[i] == ')') ? -1 : 0));
            str.deleteCharAt(str.length() - 1);
        }
        if(s[i] != 'a')
            rec(i+1,cnt+1,str,s,invalids,op);

    }

    public List<String> removeInvalidParentheses(String s) {
        int invalids = 0;
        int op = 0;
        for(char c : s.toCharArray()){
            if(c == '(')
                op += 1;
            else if(c == ')'){
                op -= 1;
                if(op < 0){
                    invalids += 1;
                    op = 0;
                }
            }
        }
        invalids += op;
        System.out.println(invalids);
        sets = new HashSet<>();
        rec(0,0,new StringBuffer(""),s.toCharArray(),invalids,0);
        List<String> sol = new ArrayList<>();
        for(String x : sets)
            sol.add(x);
        return sol;
    }
}