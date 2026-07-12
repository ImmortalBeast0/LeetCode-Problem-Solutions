class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
            return arr;
        if(n == 1){
            arr[0] = 1;
            return arr;
        }

        vector<int> pos(n);
        iota(pos.begin(),pos.end(),0);
        sort(pos.begin(),pos.end(),
            [&](int a ,int b){
                return arr[a] < arr[b];
            }
        );
        vector<int> sol(n);
        int pre = -1e9-1;
        int rank = 0;
        for(int i=0;i<n;i++){
            if(arr[pos[i]] != pre){
                rank += 1;
                pre = arr[pos[i]];
                sol[pos[i]] = rank;
            }else
                sol[pos[i]] = rank;
        }

        return sol;
    }
};