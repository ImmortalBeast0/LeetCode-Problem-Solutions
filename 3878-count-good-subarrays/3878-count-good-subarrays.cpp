class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
       int n = nums.size();

        
        vector<long long> lt(n,0);
        {
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && (nums[st.top()] | nums[i]) == nums[i] && nums[st.top()] < nums[i])
                st.pop();
            if(!st.empty())
                lt[i] = i - st.top();
            else
                lt[i] = i+1;
            st.push(i);
        }
        }
        vector<long long> rt(n,0);
        {
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && (nums[st.top()] | nums[i]) == nums[i])
                st.pop();
            if(!st.empty())
                rt[i] = st.top() - i;
            else
                rt[i] = n - i;
            st.push(i);
        }
        }

        long long sol = 0;
        for(int i=0;i<n;i++)
            sol += (long long)lt[i] * rt[i];

        return sol;
    }
};