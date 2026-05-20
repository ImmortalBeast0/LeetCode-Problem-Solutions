class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int n = A.size();
        int cnt = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]] == 0)
                cnt += 1;
            mp[B[i]]--;
            if(mp[B[i]] == 0)
                cnt += 1;
            ans.push_back(cnt);
        }

        return ans;
    }
};