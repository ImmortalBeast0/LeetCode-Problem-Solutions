class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rem = 1;
        int n = digits.size();
        for(int i=n-1;i>=0;i--){
            int num = digits[i] + rem;
            digits[i] = num % 10;
            rem = num / 10;
        }
        vector<int> ans;
        if(rem)
            ans.push_back(rem);
        for(int i=0;i<n;i++)
            ans.push_back(digits[i]);
        return ans;
    }
};