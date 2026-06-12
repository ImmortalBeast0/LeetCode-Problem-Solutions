import java.util.ArrayList;

class Solution {
    final static int mod = (int)(1e9) + 7;

    static int[] pow_2 = new int[(int)1e5 + 3];

    static void calc(){
        pow_2[0] = 1;
        for(int i=1;i<(int)1e5+3;i++)
            pow_2[i] = (2 * pow_2[i-1]) % mod;
    }

    int n;
    int logN;
    ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    int[] depth;
    int[][] ancestor;

    void dfs(int u ,int p ,int d){

        depth[u] = d;
        ancestor[0][u] = p;
        for(int i=1;i<logN;i++){
            if(ancestor[i-1][u] != -1)
                ancestor[i][u] = ancestor[i-1][ancestor[i-1][u]];
        }

        for(int v : adj.get(u)){
            if(v == p)
                continue;
            dfs(v,u,d+1);
        }
    } 

    int findLCA(int u ,int v){
        if(depth[u] < depth[v]){
            int tmp = u;
            u = v;
            v = tmp;
        }

        int diff = depth[u] - depth[v];
        
        int p_u = u;
        int p_v = v;

        int i = 0;
        while(diff > 0){
            if((diff & 1) == 1){
                p_u = ancestor[i][p_u];
            }
            i += 1;
            diff >>= 1;
        }

        if(p_u == p_v)
            return p_u;

        for(i=logN-1;i>=0;i--){
            if(ancestor[i][p_u] != ancestor[i][p_v]){
                p_u = ancestor[i][p_u];
                p_v = ancestor[i][p_v];
            }
        }

        return ancestor[0][p_u];
    }

    public int[] assignEdgeWeights(int[][] edges, int[][] q) {
        
        calc();
        n = edges.length + 1;
        logN = (int)Math.ceil(Math.log10(n)/Math.log10(2)) + 1;

        for(int i=0;i<n;i++)
            adj.add(new ArrayList<Integer>());
        depth = new int[n];
        ancestor = new int[logN][n];

        for(int[] e : edges){
            int u = e[0] ,v = e[1];
            u -= 1; v -= 1;
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        dfs(0,-1,0);

        int[] ans = new int[q.length];

        for(int i=0;i<q.length;i++){
            int u = q[i][0] ,v = q[i][1];
            u -= 1; v -= 1;
            int lca = findLCA(u,v);
            int dist = depth[u] + depth[v] - (2 * depth[lca]);
            if(dist == 0)
                ans[i] = 0;
            else
                ans[i] = pow_2[dist - 1];
        }

        return ans;
    }
}