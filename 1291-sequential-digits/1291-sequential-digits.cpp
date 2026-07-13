class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        string l = to_string(low);
        string r = to_string(high);

        int lb = l.size();
        int ub = r.size();
        vector<int> sol;
        for(int i=lb;i<=ub;i++){
            for(int d=1;d<=9;d++){
                    long  x = 0;
                    long ten = 1;
                    int j = i;
                    int cnt = d;
                    while(j-- && cnt < 10){
                        x *= ten;
                        x += cnt; 
                        ten = 10;
                        cnt += 1;
                    }
                    
                    if(j == -1 && x >= low && x <= high)
                        sol.push_back(x);
                }
        }

        return sol;
    }
};