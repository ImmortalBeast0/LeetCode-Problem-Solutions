class Solution {
public:
    set<vector<int>> ans;
    vector<int> ss;

    void rec(int i ,vector<int>& nums){
        if(i >= nums.size()){
            ans.insert(ss);
            return ;
        }

        rec(i+1,nums);
        ss.push_back(nums[i]);
        rec(i+1,nums);
        ss.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(),nums.end());
        rec(0,nums);
        vector<vector<int>> sol(ans.begin(),ans.end());
        return sol;
    }
};