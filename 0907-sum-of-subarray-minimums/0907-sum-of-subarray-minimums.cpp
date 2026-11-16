class Solution {
public:
    using ll = long long;
    int sumSubarrayMins(vector<int>& nums) {
       int n = nums.size();
       vector<ll> lt(n),rt(n);
       {
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if(!st.empty())
                lt[i] = i - st.top();
            else
                lt[i] = i + 1;
            st.push(i);
        }
       }
       {
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if(!st.empty())
                rt[i] = st.top() - i;
            else
                rt[i] = n - i;
            st.push(i);
        }
       }

       ll sol = 0;
       for(int i=0;i<n;i++){
            sol += lt[i] * rt[i] * nums[i];
            sol %= (int)1e9 + 7;
        }

        return sol;
    }
};