#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9 + 7)

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()

static const int N = (int)1e6;
bool isPrime[N+2];
bool flag = true;

class Solution{
public:

    
    void seive(){
        flag = false;
        memset(isPrime,1,sizeof(isPrime));
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i<=N;i++){
            if(isPrime[i]){
                for(int j=2;j*i<=N;j++)
                    isPrime[i*j] = false;
            }
        }
    }

    void add(vector<bool>& vis ,queue<int>& q ,vector<int>& inds){
        for(int ind : inds){
            if(!vis[ind]){
                q.push(ind);
                vis[ind] = 1;
            }
        }
    }

    int minJumps(vector<int>& nums){
        
        if(flag)
            seive();

        int n = nums.size();
        unordered_map<int,vector<int>> indices;
        for(int i=0;i<n;i++){
            if(isPrime[nums[i]])
                indices[nums[i]].pb(i);
        }

        int ans_depth = 0;
        queue<int> q;
        vector<bool> vis(n,0);

        q.push(n-1);
        vis[n-1] = 1;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();

                if(u == 0)
                    return ans_depth;

                if(u+1 < n && !vis[u+1]){
                    q.push(u+1);
                    vis[u+1] = 1;
                }

                if(u-1 >= 0 && !vis[u-1]){
                    q.push(u-1);
                    vis[u-1] = 1;
                }

                if(isPrime[nums[u]]){
                    add(vis,q,indices[nums[u]]);
                    indices[nums[u]].clear();
                }else{
                    int tmp = nums[u];
                    for(int k=2;k*k<=tmp;k++){
                        if(isPrime[k] && nums[u] % k == 0){
                            add(vis,q,indices[k]);
                            indices[k].clear();
                            while(tmp % k == 0)
                                tmp /= k;    
                        }
                    }
                    if(tmp > 1){
                       add(vis,q,indices[tmp]); 
                       indices[tmp].clear();
                    }
                }

            }
            ans_depth += 1;
        }

        return ans_depth - 1;
    }
};