class Solution {
    int n;
    List<List<Long>> sets = new ArrayList<>();

    void rec(int i ,int cnt ,long lcm ,int[] nums){
        if(i >= n){
            sets.get(cnt).add(lcm);
            return ;
        }
        rec(i+1,cnt,lcm,nums);
        rec(i+1,cnt + 1,lcm(lcm,nums[i]),nums);
    }

    boolean check(long nth ,int k){
        
        long cnt = 0;
        for(int i=1;i<=n;i++){
            for(long x : sets.get(i)){
                if(i % 2 == 1)
                    cnt += (nth / x);
                else
                    cnt -= (nth / x);
            }
        }

        return cnt >= k;
    }

    public long findKthSmallest(int[] coins, int k) {

        n = coins.length;
        for(int i=0;i<=n;i++){
            sets.add(new ArrayList<Long>());
        }
        rec(0,0,1,coins);
        long lb = 1 ,ub = 50 * (long)1e9;
        long ans = -1;
        while(lb <= ub){
            long mi = (ub - lb) / 2 + lb;
            if(check(mi,k)){
                ans = mi;
                ub = mi - 1;
            }else
                lb = mi + 1;
        }

        return ans;
    }


    long lcm(long a ,long b){
        return (a * b) / gcd(a,b);
    }

    long gcd(long a ,long b){
        if(b == 0)
            return a ;
        return gcd(b ,a % b);
    }
}