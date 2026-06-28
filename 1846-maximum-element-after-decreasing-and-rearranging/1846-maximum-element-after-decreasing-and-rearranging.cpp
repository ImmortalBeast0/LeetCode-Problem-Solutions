class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr){
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int x : arr)
            pq.push(x);

        vector<int> ans;

        ans.push_back(1);
        pq.pop();

        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            int pre = *(ans.rbegin());

            if(abs(pre - x) <= 1)
                ans.push_back(x);
            else
                ans.push_back(pre+1);
        }

        return *max_element(ans.begin(),ans.end());
    }
};