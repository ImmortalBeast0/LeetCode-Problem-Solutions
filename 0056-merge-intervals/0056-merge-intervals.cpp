class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in){
        int n = in.size();
        sort(in.begin(),in.end());
        vector<vector<int>> sol;
        sol.push_back(in[0]);
        for(int i=1;i<n;i++){
            vector<int> a = *(sol.rbegin());
            vector<int> b = in[i];
            if(a[1] >= b[0]){
                sol.pop_back();
                sol.push_back({a[0],max(a[1],b[1])});
            }else{
                sol.push_back(b);
            }
        }

        return sol;
    }
};