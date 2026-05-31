class Solution {
public:
    int n;
    int budget;
    int min_cost;
    int dp[1032][1532];
    int rec(int i ,int rem ,vector<int>& count ,vector<int>& costs){
        if(i >= n)
            return (budget - rem) / min_cost; 

        if(dp[i][rem] != -1)
            return dp[i][rem];

        int ans = -1e9;
        if(rem + costs[i] <= budget){
            ans = max(ans,rec(i+1,rem+costs[i],count,costs) + count[i] + 1);
        }
        ans = max(ans,rec(i+1,rem,count,costs));

        return dp[i][rem] = ans;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget_){

        vector<int> factors;
        vector<int> costs;

        for(vector<int> vi : items){
            factors.push_back(vi[0]);
            costs.push_back(vi[1]);
        }

        n = factors.size();
        budget = budget_;
        min_cost = *min_element(costs.begin(),costs.end());

        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && factors[i] % factors[j] == 0){
                    arr[j] += 1;
                }
            }
        }

        memset(dp,-1,sizeof(dp));
        return rec(0,0,arr,costs);
    }
};