class Solution {

    boolean isChar(char c){
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    public String reverseOnlyLetters(String str){
        int n = str.length();
        char[] s = str.toCharArray();
        int i = 0 ,j = n - 1;
        while(i < j){
            if(!isChar(s[i]))
                i += 1;
            
            if(!isChar(s[j]))
                j -= 1;

            if(isChar(s[i]) && isChar(s[j])){
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i += 1;
                j -= 1;
            }
        }   

        StringBuffer sb = new StringBuffer("");
        for(char c : s)
            sb.append(c);
        return sb.toString();
    }
}