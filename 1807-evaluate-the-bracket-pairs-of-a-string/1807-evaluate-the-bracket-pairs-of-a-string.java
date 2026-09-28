class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        StringBuffer ans = new StringBuffer("");
        StringBuffer sb = new StringBuffer("");
        boolean op = false;
        HashMap<String,String> mp = new HashMap<>();
        for(List<String> strs : knowledge){
            mp.put(strs.get(0),strs.get(1));
        }
        for(char c : s.toCharArray()){
            if(c == '('){
                op = true;
            }else if(c == ')'){
                op = false;
                ans.append(mp.getOrDefault(sb.toString(),"?"));
                sb.setLength(0);
            }else if(op)
                sb.append(c);
            else
                ans.append(c);
        }
        return ans.toString();
    }
}