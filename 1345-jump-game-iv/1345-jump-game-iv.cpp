class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[arr[i]].push_back(i);

        int ans_depth = 0;
        vector<bool> vis(n,0);
        queue<int> q;

        vis[0] = 1;
        q.push(0);


        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();
                if(u == n-1)
                    return ans_depth;

                if(u+1 < n && !vis[u+1]){
                    q.push(u+1);
                    vis[u+1] = 1;
                }

                if(u - 1 >= 0 && !vis[u-1]){
                    q.push(u-1);
                    vis[u-1] = 1;
                }

                for(int i : mp[arr[u]]){
                    if(!vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }

                mp[arr[u]].clear();
            }
            ans_depth += 1;
        }

        return ans_depth;
    }
};