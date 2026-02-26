class Solution {

    private void divByTwo(StringBuilder s){
        s.deleteCharAt(s.length() - 1);
    }

    private void addOne(StringBuilder s){

        int i = s.length() - 1;

        while(i >= 0 && s.charAt(i) != '0'){
            s.setCharAt(i,'0');
            i -= 1;
        }

        if(i < 0)
            s.insert(0,'1');
        else
            s.setCharAt(i,'1');

    }

    public int numSteps(String s) {
        StringBuilder sb = new StringBuilder(s);

        int sol = 0;

        while(sb.length() > 1){

            int N = sb.length();

            if(sb.charAt(N - 1) == '0')
                divByTwo(sb);
            else
                addOne(sb);

            sol += 1;
        }

        return sol;
    }
}