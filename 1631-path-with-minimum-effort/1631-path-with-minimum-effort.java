class Solution {
    int m ,n;
    int dx[] = { -1 ,0 ,1 ,0};
    int dy[] = { 0 ,1 ,0 ,-1};
    boolean[][] vis;

    boolean check(int x ,int y){
        return  x >= 0 && x < m && y >= 0 && y < n;
    }

    boolean dfs(int i ,int j ,int max ,int[][] g){

        if(i == m-1 && j == n-1)
            return true;

        for(int d=0;d<4;d++){
            int ni = dx[d] + i;
            int nj = dy[d] + j;
            if(check(ni,nj) && !vis[ni][nj] && Math.abs(g[ni][nj] - g[i][j]) <= max){
                vis[ni][nj] = true;
                if(dfs(ni,nj,max,g))
                    return true;
            }
        }

        return false;
    }

    boolean check(int max ,int[][] g){
        vis = new boolean[m][n];
        return dfs(0,0,max,g);
    }

    public int minimumEffortPath(int[][] heights){
        m = heights.length;
        n = heights[0].length;

        int lb = 0 ,ub = 1;
        while(!check(ub,heights)){
            ub *= 2;
        }
        int ans = ub;

        while(lb <= ub){
            int mi = (ub - lb)/2 + lb;
            if(check(mi,heights)){
                ans = mi;
                ub = mi - 1;
            }else
                lb = mi + 1;
        }

        return ans;
    }
}