class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int oddcnt = 0 ,evencnt = 0;
        int alteven = 0 , altodd = 0;

        for(int x : nums){
            int num = x % 2;
            if(num){
                oddcnt += 1;
                altodd = alteven + 1;
            }else{
                evencnt += 1;
                alteven = altodd + 1;
            }
        }

        return max({oddcnt,evencnt,alteven,altodd});
    }
};