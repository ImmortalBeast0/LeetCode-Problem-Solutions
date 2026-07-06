#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9+7)


#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define F first
#define S second 
#define all(x) x.begin(),x.end()

class Solution {
public:

    //Rolling Hash DS structure
    struct RHasher{
        ll B ,MOD;
        int n;
        vector<ll> hash;
        vector<ll> pow;

        void init(vector<int>& nums ,ll B_,ll MOD_){
            n = nums.size();
            B = B_;
            MOD = MOD_;
            hash.resize(n);
            pow.resize(n);
            build(nums);
        }

        void build(vector<int>& nums){
            hash[0] = nums[0];
            pow[0] = 1;
            for(int i=1;i<n;i++){
                hash[i] = ((hash[i-1] * B) % MOD + nums[i]) % MOD;
                pow[i] = (pow[i-1] * B) % MOD;
            }
        }

        ll getHash(int l ,int r){
            if(l == 0)
                return hash[r];
            return ((hash[r] - (hash[l-1] * pow[r - l + 1]) % MOD) + MOD) % MOD;
        }

    };

    int n;
    RHasher normal ,rev;
    ll BASE = 911382323L;
    const ll MOD = 1e9 + 7; 

    bool isPalidrome(int l ,int r){
        ll hash1 = normal.getHash(l,r);
        ll hash2 = rev.getHash(n-r-1,n-l-1);
        return hash1 == hash2;
    }

    ll getSum(vector<int>& nums) {

        n = nums.size();

        //prefix sum
        vector<ll> ps(n);
        ps[0] = nums[0];
        for(int i=1;i<n;i++)
            ps[i] = nums[i] + ps[i-1];

        //Rolling Hash Object initialzation
        normal.init(nums,BASE,MOD);

        vector<int> revNums(all(nums));
        reverse(all(revNums));
        rev.init(revNums,BASE,MOD);


        ll sol = 0;
        for(int i=0;i<n;i++){

            //Odd Length Palidromic Subarray at center have ith index
            int len = 0;
            int maxLen = min(i,(n-1) - (i+1) + 1); //as ith index as center
            int lb = 0 ,ub = maxLen;
            while(lb <= ub){
                int mid = (ub - lb)/2 + lb;
                if(isPalidrome(i-mid,i+mid)){
                    len = mid;
                    lb = mid + 1;
                }else
                    ub = mid - 1;
            }

            sol = max(sol,getSum(i-len,i+len,ps)); //odd at center at i maximized 

            //Even length Palindromic Subarray at ith index in left part of the subarray 
            if(i+1 >= n || nums[i] != nums[i+1])
                continue; // if not possible
            //then

            len = 0;
            maxLen = min(i,(n-1) - ((i+1)+1) + 1); //just index length formula (r - l + 1)
            lb = 0 ,ub = maxLen;
            while(lb <= ub){
                int mid = (ub - lb)/2 + lb;
                if(isPalidrome(i-mid,i+1+mid)){
                    len = mid;
                    lb = mid + 1;
                }else
                    ub = mid - 1;
            }

            sol = max(sol,getSum(i-len,i+1+len,ps));
        }

        return sol;
    }

    //Prefix Sum ,Range Sum GET function
    ll getSum(int l ,int r ,vector<ll>& ps){
        if(l == 0)
            return ps[r];
        return ps[r] - ps[l-1];
    }

};