class Solution {
public:
    using ll = long long;
    int const mod = ((int)1e9+7);

    ll pow(ll a ,ll b){
        ll ans = 1;
        while(b != 0){
            if(b & 1){
                ans *= a;
                ans %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }

        return ans;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.length();
        reverse(s.begin(),s.end());

        ll ten = 1;
        vector<ll> dps(n);
        vector<ll> ps(n);
        vector<ll> power(n);
        dps[0] = s[0] - '0';
        ps[0] = s[0] - '0';
        if(s[0] != '0')
            ten *= 10;
        cout << ps[0] << ' ';
        for(int i=1;i<n;i++){
            power[i] = ten;
            dps[i] = (dps[i-1] + (s[i] - '0')) % mod;
            ps[i] = (ps[i-1] + ((s[i] - '0') * ten) % mod) % mod;
            if(s[i] != '0')
                ten = (ten * 10) % mod;
            cout << ps[i] << ' ';
        }

        vector<int> sol;
        for(vector<int> q : queries){
            int l = n - q[1] - 1;
            int r = n - q[0] - 1;

            ll num = ps[r];
            ll sum = dps[r];
            if(l > 0){
                num = (num - ps[l-1] + mod) % mod;
                num = (num * (pow(power[l],mod-2))) % mod;
                sum = (sum - dps[l-1] + mod) % mod;
            }

            sol.push_back((num * sum) % mod);
        }

        return sol;
    }
};