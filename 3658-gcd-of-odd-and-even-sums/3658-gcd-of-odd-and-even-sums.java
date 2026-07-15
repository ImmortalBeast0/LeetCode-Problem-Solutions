class Solution {

    int gcd(int a ,int b){
        if(b == 0)
            return a;
        return gcd(b,a % b);
    }

    public int gcdOfOddEvenSums(int n) {
        n *= 2;
        int sumOfNatural = (n * (n+1))/2;
        int sumOfEven = (n/2 * (n/2 + 1));
        int sumOfOdd = sumOfNatural - sumOfEven;
        return gcd(sumOfOdd,sumOfEven);
    }
}