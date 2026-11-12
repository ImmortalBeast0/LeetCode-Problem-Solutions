class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar){
        int m = mat.size();
        int n = mat[0].size();

        int lb = 0 ,ub = (m * n) - 1;
        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            int v = mat[mi / n][mi % n];
            if(v == tar)
                return true;
            if(v < tar)
                lb = mi + 1;
            else
                ub = mi - 1;
        }

        return false;
    }
};