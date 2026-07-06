class Solution {
public:

    bool static cmp(vector<int>& a ,vector<int>& b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),cmp);

        int maxEnd = -1;
        int sol = 0;
        //The intervals were sorted
        //ith ,li is greter than or equal to (i-1)th ,l(i-1)  -  l(i-1) <= li ,then 
        //if ri is - ri < (r(i-1)) ,means ith covered interval index
        for(vector<int> i : in){
            if(maxEnd < i[1]){
                maxEnd = i[1];
                sol += 1;
            }
        }

        return sol;
    }
};