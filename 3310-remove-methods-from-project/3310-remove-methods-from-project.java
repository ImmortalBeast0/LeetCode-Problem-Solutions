class Solution {
    List<List<Integer>> adj;
    int indeg[];
    boolean vis[]; 
    void dfs(int u){
        vis[u] = true;
        for(int v : adj.get(u)){
            indeg[v] -= 1;
            if(!vis[v])
                dfs(v);
        }
    }

    public List<Integer> remainingMethods(int n, int k, int[][] invocations){

        adj = new ArrayList<>();
        for(int i=0;i<n;i++)
            adj.add(new ArrayList<>());

        indeg = new int[n];
        for(int[] e : invocations){
            indeg[e[1]] += 1;
            adj.get(e[0]).add(e[1]);
        }
        
        vis = new boolean[n];
        dfs(k);

        boolean flag = false;
        for(int i=0;i<n;i++){
            if(vis[i] && indeg[i] > 0){
                flag = true;
                break;
            }
        }

        List<Integer> sol = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(flag || !vis[i])
                sol.add(i);
        }

        return sol;
    }
}