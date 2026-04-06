
class Solution {
public:

    vector<vector<int>> adj;
    vector<int> vis;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
        adj.resize(numCourses);
        vis.resize(numCourses,0);
        vector<int> indeg(numCourses);
        for(auto e : prerequisites){
            int u = e[0] ,v = e[1];
            adj[u].push_back(v);
            indeg[v] += 1;
        }

        
        queue<int> q;
        vector<int> sol;
        for(int i=0;i<numCourses;i+=1)
            if(indeg[i])
                continue;
            else
                q.push(i);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            sol.push_back(u);
            for(int v : adj[u]){
                indeg[v] -= 1;
                if(indeg[v] == 0)
                    q.push(v);
            }
        }
        reverse(sol.begin(),sol.end());
       if(sol.size() != numCourses)
        return{};

        return sol;
    }
};