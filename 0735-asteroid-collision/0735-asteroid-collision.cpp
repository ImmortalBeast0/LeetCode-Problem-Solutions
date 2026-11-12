class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums){
        int n = nums.size();

        stack<int> st;
        vector<int> bns;
        for(int i=0;i<n;i++){
            bool f = true;
            while(!st.empty() && nums[i] < 0 && st.top() <= abs(nums[i])){
                if(st.top() == abs(nums[i])){
                    f = false;
                    st.pop();
                    break;
                }
                if(st.top() < abs(nums[i])){
                    st.pop();
                }
            }

            if(st.empty() && f && nums[i] < 0)
                bns.push_back(nums[i]);
            
            if(nums[i] > 0)
                st.push(nums[i]);
        }
        // reverse(bns.begin(),bns.end());
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        for(int x : ans)
            bns.push_back(x);
        return bns;
    }
};


