class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int n = in.size();
        bool flag[n];
        memset(flag,false,sizeof(flag));
        for(int i=0;i<n;i++){
            if(flag[i])
                continue;
            int a = in[i][0] ,b = in[i][1];
            for(int j=0;j<n;j++){
                int c = in[j][0] ,d = in[j][1];
                if(i != j && c <= a && b <= d){
                    flag[i] = true;
                    break;
                }
            }
        }

        int cnt = 0;
        for(bool f : flag)
            cnt += f;
        return n - cnt;
    }
};