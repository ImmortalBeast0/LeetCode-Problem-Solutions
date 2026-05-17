class Solution {
public:
    bool canReach(vector<int>& arr, int start){
        int n = arr.size();
        queue<int> q;
        vector<int> vis(n,0);

        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(arr[u] == 0)
                return true;

            if(u + arr[u] < n && !vis[u + arr[u]]){
                vis[u + arr[u]] = 1;
                q.push(u + arr[u]);
            }

            if(u - arr[u] >= 0 && !vis[u - arr[u]]){
                vis[u - arr[u]] = 1;
                q.push(u - arr[u]);
            }
        }

        return false;
    }
};