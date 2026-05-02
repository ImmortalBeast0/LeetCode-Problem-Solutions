class Solution {
public:

    bool dp[(int)1e4+1];
    bool flag = true;

    bool check(int num){

        int cnt = 0;
        while(num){
            int rem = num % 10;
            if(rem == 0 || rem == 1 || rem == 8 || rem == 2 || rem == 5 || rem == 6 || rem == 9){
                cnt += ( rem == 2 || rem == 5 || rem == 6 || rem == 9);
            }else
                return false;
            num /= 10;
        }

        return cnt;
    }

    void calc(){
        flag = false;
        for(int i=1;i<=1e4;i++)
            dp[i] = check(i);
    }

    int rotatedDigits(int n){

        if(flag)
            calc();

        int sol = 0;
        for(int i=1;i<=n;i++)
            sol += dp[i];    

        return sol;
    }
};