class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t){
        int m = mat.size();
        int n = mat[0].size();
        
        int i = 0 ,j = n - 1;
        while(i < m && j >= 0){
            int v = mat[i][j];
            if(v == t)
                return true;
            if(v < t){
                i += 1;
            }else
                j -= 1;
        }

        return false;
    }
};