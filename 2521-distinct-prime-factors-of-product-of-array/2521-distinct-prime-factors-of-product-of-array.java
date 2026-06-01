class Solution {

    boolean flag = true;

    boolean[] primes = new boolean[1032];

    public void seive(){
        flag = false;
        Arrays.fill(primes,true);

        primes[0] = primes[1] = false;

        for(int i=2;i<1032;i++){
            if(primes[i]){
                for(int j=2;j*i<1032;j++){
                    primes[i * j] = false;
                }
            }
        }

    }

    public int distinctPrimeFactors(int[] nums) {
        if(flag)
            seive();


        int cnt = 0;
        for(int i=2;i<1001;i++){
            if(primes[i]){
            for(int x : nums){
                if(x % i == 0){
                    cnt += 1;
                    break;
                }
            }
            }
        }

        return cnt;
    }
}