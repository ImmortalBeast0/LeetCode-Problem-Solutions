class Solution {
public:

    void add(queue<int> & q ,map<int,bool>& vis ,int x){
        q.push(x);
        vis[x] = true;
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        
        queue<int> q;
        map<int,bool> vis;
        q.push(x);
        vis[x] = true;
        int sol = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front();
                q.pop();
                if(x == y)
                    return sol;
                if(!vis[x+1])
                    add(q,vis,x+1);
                
                if(!vis[x-1])
                    add(q,vis,x-1);
                
                if(x % 11 == 0 && !vis[x/11])
                    add(q,vis,x/11);

                if(x % 5 == 0 && !vis[x/5])
                    add(q,vis,x/5);
                
            }
            sol += 1;
        }

        return 0;
    }
};