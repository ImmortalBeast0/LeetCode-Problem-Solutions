class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins){

        int mx = *max_element(costs.begin(),costs.end());

        int count[mx+1];
        memset(count,0,sizeof(count)); // 1 ,0 ,-1 

        for(int x : costs)
            count[x] += 1;

        for(int i=1;i<=mx;i++)
            count[i] += count[i-1];

        //in count[i] each value represent the last index of corresponding i 
        vector<int> ans(costs.size());
        for(int i=costs.size()-1;i>=0;i--){
            int idx = count[costs[i]] - 1;
            ans[idx] = costs[i];
            count[costs[i]] -= 1;
        }

        int sol = 0;
        int used = 0;

        for(int x : ans){
            if(x + used <= coins){
                used += x;
                sol += 1;
            }
        }

        return sol;
    }   
};