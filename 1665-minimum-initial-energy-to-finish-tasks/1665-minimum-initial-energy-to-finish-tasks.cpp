class Solution {
public:

    bool static cmp(vector<int>& a,vector<int>& b){
        return a[1] - a[0] < b[1] - b[0];
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        reverse(tasks.begin(),tasks.end());

        int minn = 0;
        int sol = 0;
        for(vector<int> a : tasks)
            minn += a[0];
        sol += minn;
        for(vector<int> a : tasks){
            if(minn < a[1]){
                sol += (a[1] - minn);
                minn += (a[1] - minn);
            }
            minn -= a[0];
        }

        return sol;
    }
};