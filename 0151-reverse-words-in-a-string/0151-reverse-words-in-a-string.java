import java.util.*;
class Solution {
    public String reverseWords(String s) {
        StringTokenizer st = new StringTokenizer(s);
        List<String> list = new ArrayList<>();
        while(st.hasMoreTokens()){
            list.add(st.nextToken());
        }

        int n = list.size();
        StringBuilder sb = new StringBuilder();
        for(int i=n-1;i>0;i--){
            sb.append(list.get(i));
            sb.append(" ");
        }
        sb.append(list.get(0));
        return sb.toString();
    }
}