#define all(x) x.begin(),x.end()
class Solution {
public:

    vector<int> par;
    vector<int> sz;

    int find_par(int u){
        if(u == par[u])
            return u;
        return par[u] = find_par(par[u]);
    }

    void union_set(int u ,int v){
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv)
            return ;
        if(sz[pu] < sz[pv])
            swap(pu,pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
    }

    void init(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int bs(vector<int>& nums ,int tar){
        int ans = 0;
        int lb = 0 ,ub = nums.size() - 1;
        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            if(nums[mi] <= tar){
                ans = mi;
                lb = mi + 1;
            }else
                ub = mi - 1;
        }
        return ans;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        init(n);
        int i = 0;
        while(i < n){
            int r = bs(nums,nums[i] + maxDiff);
            for(int j=i+1;j<n&&j<=r;j++)
                union_set(i,j);
            if(i == r)
                i += 1;
            else
                i = r;
        }
        
        vector<bool> ans;
        for(vector<int> q : queries){
            int u = q[0] ,v = q[1];
            ans.push_back(find_par(u) == find_par(v));
        }

        return ans;
    }
};