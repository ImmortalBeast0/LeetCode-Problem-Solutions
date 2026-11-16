class Solution {
public:

    string sum(string s){
        int num = 0;
        for(char c : s)
            num += (c - '0');
        return to_string(num);
    }

    string digitSum(string s, int k) {
        int n = s.length();
        string t;
        while(n > k){
            int it = (n / k) + (n % k != 0);
            for(int i=0;i<it;i++)
                t += sum(s.substr(i*k,k));
            s = t;
            t = "";
            n = s.length();
        }

        return s;
    }
};