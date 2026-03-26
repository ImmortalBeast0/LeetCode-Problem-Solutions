#define all(x) x.begin(),x.end()
class Solution {
public: 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        if(accumulate(all(gas),0) < accumulate(all(cost),0))
            return -1;

        int n = gas.size();
        int tank = 0;
        int sol = 0;
        for(int i=0;i<n;i+=1){
            tank += gas[i] - cost[i];
            if(tank < 0){
                sol = i+1;
                tank = 0;
            }
        }

        return sol;
    }
};