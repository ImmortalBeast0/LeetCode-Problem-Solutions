class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries){
        
        vector<int> idx(n) ,pos(n) ,sol;

        // idx for tracking the index after sorting 
        //pos for track the every value original positions 

        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),
            [&](int a ,int b){
                return nums[a] < nums[b];
            }); // we sort the idx by order of values in ASC

        for(int i=0;i<n;i++)
            pos[idx[i]] = i;
        //fix the original position of every values

        //my style Binary Lifting
        int m = 32 - __builtin_clz(n);
        vector<vector<int>> up(m,vector<int>(n));

        for(int i=0,lt=0;i<n;i++){
            while(nums[idx[i]] - nums[idx[lt]] > maxDiff) lt += 1;

            // after sorted finding the lt point of the interval where the components connect 

            up[0][i] = lt; // 2^0 ancestor is lt
        }

        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                up[j][i] = up[j-1][up[j-1][i]];
            }
        }
        // binary lifting 

        for(auto &q : queries){
            int x = pos[q[0]];
            int y = pos[q[1]];
            if(x > y)
                swap(x,y);

            if(x == y){
                sol.push_back(0);
                continue;
            }

            int cnt = 0;
            for(int i=m-1;i>=0;i--){
                if(up[i][y] > x){
                    y = up[i][y];
                    cnt += (1 << i);
                }
            }

            sol.push_back(up[0][y] <= x ? cnt + 1 : -1);
        }

        return sol;
    }
};

// I understand , but not re-created 