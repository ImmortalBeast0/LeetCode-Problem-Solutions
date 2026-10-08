class Solution {
    public String removeOuterParentheses(String str) {
        int n = str.length();
        int op = 0;
        char[] arr = str.toCharArray();
        StringBuffer sb = new StringBuffer("");
        for(int i=0;i<n;i++){
            if(arr[i] == '('){
                op += 1;
                if(op != 1)
                    sb.append(arr[i]);
            }else{
                op -= 1;
                if(op != 0)
                    sb.append(arr[i]);
            }
        }

        return sb.toString();
    }
}