class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long sum = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                sum += grid[i][j];
        long rowSum = 0;
        for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++)
                rowSum += grid[i][j];
            if(sum - rowSum == rowSum)
                return true;
        }
        long colSum = 0;
        for(int j=0;j<m;j++){
            
            for(int i=0;i<n;i++)
                colSum += grid[i][j];
            if(sum - colSum == colSum)
                return true;
        }
        cout << sum << endl;
        return false;
    }
};