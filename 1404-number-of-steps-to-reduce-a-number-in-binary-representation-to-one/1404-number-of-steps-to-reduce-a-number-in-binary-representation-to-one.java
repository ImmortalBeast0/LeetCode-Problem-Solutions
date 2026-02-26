class Solution {
    public int numSteps(String s) {
        int N = s.length();

        int sol = 0;
        int carry = 0;
        for(int i=N-1;i>0;i--){
            int digit = s.charAt(i) -'0' + carry;
            // System.out.println(s.charAt(i) - '0')
            if(digit % 2 == 1){
                carry = 1;
                sol += 2;
            }else
                sol += 1;
        }

        return sol + carry;
    }
}