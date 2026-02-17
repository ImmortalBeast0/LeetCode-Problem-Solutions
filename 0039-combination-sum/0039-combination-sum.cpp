class Solution {
public:
    int n , t;
    vector<vector<int>> ans ;
    void rec(int i ,int sum ,vector<int>& num ,vector<int>& cand){

        if(sum == t){
            if(find(ans.begin(),ans.end(),num) == ans.end())
                ans.push_back(num);
            return ;
        }
        if(i >= n)
            return ;
        if(sum + cand[i] <= t){
            num.push_back(cand[i]);
            rec(i,sum+cand[i],num,cand);
            num.pop_back();
        }
        if(sum + cand[i] <= t){
            num.push_back(cand[i]);
            rec(i+1,sum+cand[i],num,cand);
            num.pop_back();
        }
        rec(i+1,sum,num,cand);
    }

    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        n = cand.size();
        t = target;
        vector<int> num;
        rec(0,0,num,cand);
        return ans;
    }
};