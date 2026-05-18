class Solution {
public:
    using ll = long long;
    struct Hasher{
        vector<ll> fhash;
        vector<ll> powk;
        int sz;
        ll k ,mod;

        void init(vector<int>& nums ,ll k_,ll mod_){
            sz = nums.size();
            fhash.resize(sz);
            powk.resize(sz);
            k = k_;
            mod = mod_;

            powk[0] = 1;
            fhash[0] = nums[0];
            for(int i=1;i<sz;i++){
                fhash[i] = ((fhash[i-1] * k) % mod + nums[i]) % mod; 
                powk[i] = (powk[i-1] * k) % mod;
            }
        }

        ll getHash(int l ,int r){
            if(l == 0)
                return fhash[r];
            return (((fhash[r] - (fhash[l-1] * powk[r - l + 1]) % mod) % mod) + mod) % mod;
        }        

    };

    bool check(int len ,vector<int>& nums ,Hasher& hasher){
        map<ll,int> mp;
        for(int i=len-1;i<nums.size();i++){
            ll hash = hasher.getHash(i-len+1,i);
            mp[hash]++;
        }
        for(auto &[x,f] : mp)
            if(f <= 1)
                return true;
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        Hasher hasher;
        hasher.init(nums,1e5+3,999999937);

        int lb = 1 ,ub = nums.size() ,ans = nums.size();
        while(lb <= ub){
            int mi = ( lb + ub) / 2;
            if(check(mi,nums,hasher)){
                ub = mi - 1;
                ans = mi;
            }else{
                lb = mi + 1;
            }
        }

        return ans;
    }
};