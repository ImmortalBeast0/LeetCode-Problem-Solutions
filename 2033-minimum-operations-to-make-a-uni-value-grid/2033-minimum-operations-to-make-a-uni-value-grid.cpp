class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int k){
        vector<int> arr;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                arr.push_back(grid[i][j]);

        int n = arr.size();
        sort(arr.begin(),arr.end());
        int median;
        if(n % 2)
            median = arr[n/2];
        else
            median = arr[n/2 - 1];


        int sol = 0;
        for(int x : arr){
            int diff = abs(x - median);
            if(diff % k > 0)
                return -1;
            sol += diff/k;
        }

        return sol;
    }
};