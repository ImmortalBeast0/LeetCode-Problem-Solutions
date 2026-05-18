class Solution {
public:
    using ll = long long;

    ll getXor(int l ,int r ,vector<ll>& ps){
        if(l == 0)
            return ps[r];
        
        return ps[r] ^ ps[l-1];
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries){
        
        vector<ll> nums;
        for(char c : s){
            ll id = 1 << (c - 'a');
            nums.push_back(id);
        }

        int n = s.length();
        vector<ll> ps(n);
        ps[0] = nums[0];
        for(int i=1;i<n;i++){
            ps[i] = (ps[i-1] ^ nums[i]);
        }

        vector<bool> ans;
        for(vector<int> q : queries){
            int l = q[0] ,r = q[1];
            int k = q[2];

            ll x = getXor(l,r,ps);
            int cnt = __builtin_popcount(x);
            ans.push_back(cnt/2 <= k);
        }

        return ans;
    }   
};