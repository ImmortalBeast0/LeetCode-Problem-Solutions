class Solution {
public:
    using ll = long long;
    int m ,n;
    int const mod = (1e9+7);

    vector<ll> merge(vector<ll>& a ,vector<ll>& b){
        if(a[0] == b[0]){
            a[1] += b[1];
            a[1] %= mod;
            return a;
        }
        if(a[0] > b[0])
            return a;
        return b;
    }
    unordered_map<int,unordered_map<int,vector<ll>>> mp;
    vector<ll> rec(int i ,int j ,vector<string>& b){

        if(i >= m-1 && j >= n-1)
            return {0,1};
        
        if(mp.find(i) != mp.end()){
            if(mp[i].find(j) != mp[i].end())
                return mp[i][j];
        }

        vector<ll> ans = {(int)-1e9,1};

        int val = 0;
        if(b[i][j] != 'E')
            val = b[i][j] - '0';
        vector<ll> a;

        if(i+1 < m && b[i+1][j] != 'X'){
            a = rec(i+1,j,b);
            a[0] += val;
            a[0] %= mod;
            ans = merge(ans,a);
        }
        if(j+1 < m && b[i][j+1] != 'X'){
            a = rec(i,j+1,b);
            a[0] += val;
            a[0] %= mod;
            ans = merge(ans,a);
        }
        if(i+1 < m && j+1 < n && b[i+1][j+1] != 'X'){
            a = rec(i+1,j+1,b);
            a[0] += val;
            a[0] %= mod;
            ans = merge(ans,a);
        }

        return mp[i][j] = ans;
    }

    vector<int> pathsWithMaxScore(vector<string>& b) {
        m = b.size();
        n = b[0].size();
        vector<ll> sol = rec(0,0,b);
        if(sol[0] < 0)
            sol[0] = sol[1] = 0;
        return {(int)sol[0],(int)sol[1]};
    }
};