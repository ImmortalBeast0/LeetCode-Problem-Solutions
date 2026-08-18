class DSU{
    HashMap<Integer,Integer> vis;
    int mx;
    int []par;
    int []sz;

    int build(int[] nums){
        mx = 1;
        vis = new HashMap<>();
        int n = nums.length;
        par = new int[n];
        sz = new int[n];
        for(int i=0;i<n;i++){
            int x = nums[i];
            vis.put(x,vis.getOrDefault(x,i));
            par[i] = i;
            sz[i] = 1;
        }
        for(int x : vis.keySet()){
            if(vis.containsKey(x - 1))
                union(vis.get(x),vis.get(x - 1));
        }

        return mx;
    }

    int find(int i){
        if(i == par[i])
            return i;
        return par[i] = find(par[i]);
    }


    boolean union(int i ,int j){
        int pi = find(i);
        int pj = find(j);
        if(pi == pj)
            return false;

        if(sz[pi] < sz[pj]){
            int t = pi;
            pi = pj;
            pj = t;
        }

        sz[pi] += sz[pj];
        mx = Math.max(sz[pi],mx);
        par[pj] = pi;
        return true;
    }
}

class Solution {
    public int longestConsecutive(int[] nums){
        if(nums.length == 0)
            return 0;
        DSU dsu = new DSU();
        return dsu.build(nums);
    }
}