class Solution {
    public int[] gcdValues(int[] nums, long[] queries) {
        int n_mx = nums[0];
        int n = nums.length;
        for(int x : nums)
            n_mx = Math.max(n_mx,x);

        long[] g = new long[n_mx+1];
        //intially the array as a Freq Array 
        // there is no -ve values 

        for(int x : nums)
            g[x] += 1;

        //by seive style ,going to find the # numbers which divisible by i
        for(int i=1;i<=n_mx;i++){
            for(int j=i+i;j<=n_mx;j+=i)
                g[i] += g[j];
        }

        // now each g[i] , tells the # numbers is a divisible by i
        // we need #pairs divisible by i , so then we have K numbers ,we can form (K * (k-1))/2 pairs ,using that 
        for(int i=0;i<=n_mx;i++){
            g[i] = (g[i] * (g[i]-1)) / 2;
        }

        //now the array have , number of pairs which is divided by the i 
        // but we need a #pairs for where i is a GCD 
        // for that we need to find ,the i is a exactly divide the pairs 
        //because now the pair are i is common divisor not GCD
        //G[i] tells #pair divide by i
        // Exactly[i] = G[i] - Exactly[i*2] - Exactly[i*3] .... - Exactly[i*K]. i*k < n_mx;

        //same seive style loop
        for(int i=n_mx;i>0;i--){
            for(int j=i+i;j<=n_mx;j+=i)
                g[i] -= g[j];
        }

        //finally G[i] tells , #pair which is only divible by i
        //which means GCD(that pair) is i

        // in the question we need for particular mid , find the G <= #pairs 
        //so compute prefix_sum ,it tells ,till i G #pairs 
        for(int i=1;i<=n_mx;i++)
            g[i] += g[i-1];
    
        System.out.println(Arrays.toString(g));
        int sol[] = new int[queries.length];
        for(int i=0;i<queries.length;i++){
            long k = queries[i] + 1;
            int lb = 1,ub = n_mx;
            int ans = 1;
            while(lb <= ub){
                int mi = (ub - lb)/2 + lb;
                if(g[mi] >= k){
                    ans = mi;
                    ub = mi - 1;
                }else
                    lb = mi + 1;
            }
            sol[i] = ans;
        }

        return sol;
    }   
}
/*

    we know we can find the Kth value without generating the all pairs 
    we been seen in the Kth pair sum 

    #(SUM <=) >= Kth 
    minimizing this search space , we can get 

    let assume ,we need G 

    G - gcd(some pair) values 

    now we need to Calc(#(G <=))

    for that we are going to generate the 
    by seive logic ,
    each number 
    number of pairs it divides it have 
*/