class Solution {

    int help(char c){
        if('R' == c)
            return 0;
        else if('B' == c)
            return 1;
        else
            return 2;
    }

    public int findColoredRoot(int[][] edges, String colors){
        int n = edges.length + 1;
        int[] in = new int[n];
        int[] out = new int[n];
        for(int[] e : edges){
            int u = e[0];
            int v = e[1];
            char a = colors.charAt(u);
            char b = colors.charAt(v);
            if(a == b)
                return -1;
            if((help(a) + 1) % 3 == help(b)){
                in[v] += 1;
                out[u] += 1;
            }else{
                in[u] += 1;
                out[v] += 1;
            }
        }

        int ans = -1;
        for(int i=0;i<n;i++){
            if(in[i] > 1 || out[i] > 2)
                return -1;
            if(in[i] == 0){
                if(ans != -1)
                    return -1;
                ans = i;
            }
        }

        return ans;
    }
}