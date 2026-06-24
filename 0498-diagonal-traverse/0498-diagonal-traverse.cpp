class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> arr(m+n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i+j].push_back(mat[i][j]);
            }
        }

        for(int i=0;i<m+n;i+=2)
            reverse(arr[i].begin(),arr[i].end());

        vector<int> ans;
        for(vector<int> a : arr){
            for(int x : a)
                ans.push_back(x);
        }

        return ans;
    }
};