class Solution {
public:

    int numberOfWaves(int num){
        string s = to_string(num);
        int n = s.length();
        if(n < 3)
            return 0;
        int peak = 0 ,valley = 0;
        for(int i=1;i<n-1;i++){
            peak += (s[i] > s[i-1] && s[i] > s[i+1]);
            valley += (s[i] < s[i-1] && s[i] < s[i+1]);
        }

        return peak + valley;
    }

    int totalWaviness(int num1, int num2){

        int ans = 0;
        for(int i=num1;i<=num2;i++)
            ans += numberOfWaves(i);

        return ans;
    }
};