class Solution {
public:
    using ll = long long;
    struct Manacher{
        vector<int> p;
        vector<ll> ps;

        void init(vector<int> nums){
            vector<int> arr;
            for(int x : nums){
                arr.push_back(0);
                arr.push_back(x);
            }

            arr.push_back(0);
             
            build(arr);  
        }

        void build(vector<int> nums){

            int n = nums.size();
            p.assign(n,1);
            ps.assign(n,0);

            ps[0] = nums[0];
            //boundary box
            int l = 1, r = 1;
            for(int i=1;i<n;i++){
                ps[i] = (ps[i-1] + nums[i]);

                if(i < r)
                    p[i] = max(1,min(r-i,p[l + (r - i)]));
                while(i-p[i] >= 0 && i+p[i] < n && nums[i - p[i]] == nums[i + p[i]])
                    p[i] += 1;

                if(i + p[i] > r){
                    l = i - p[i];
                    r = i + p[i];
                }
            }
        }

        ll getValue(int idx){
            int len = p[idx] - 1;
            return getSum((idx-len),idx+len);
        }

        ll getSum(int l ,int r){
            if(l == 0)
                return ps[r];
            return ps[r] - ps[l-1];
        }
    }m;

    long long getSum(vector<int>& nums) {
        m.init(nums);
        long long sol = 0;
        for(int i=0;i<2*nums.size()+1;i+=1){
            sol = max(sol,m.getValue(i));
        }
        return sol;
    }
};