#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<vector<int>> ps;

    void prefixsum(int n,int m,vector<vector<int>> &nums){

        ps.resize(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    ps[i][j] = nums[i][j];
                }else if(i==0){
                    ps[i][j] = ps[i][j-1] + nums[i][j];
                }else if(j==0){
                    ps[i][j] = ps[i-1][j] + nums[i][j];
                }else{
                    ps[i][j] = ps[i-1][j] + ps[i][j-1] + nums[i][j] - ps[i-1][j-1];
                }
            }
        }

    }

    int countSubmatrices(vector<vector<int>>& grid, int k){
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        prefixsum(n,m,grid);


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if( ps[i][j] <= k){
                    cnt++;
                }

            }
        }

        return cnt;
        
    }
};
