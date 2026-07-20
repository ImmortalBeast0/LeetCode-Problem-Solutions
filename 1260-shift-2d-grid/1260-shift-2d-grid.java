class Solution {

    void reverseList(List<Integer> arr ,int st ,int en){
        while(st < en){
            int tmp = arr.get(st);
            arr.set(st,arr.get(en));
            arr.set(en,tmp);
            st += 1;
            en -= 1;
        }
    }

    public List<List<Integer>> shiftGrid(int[][] grid, int k){
        int m = grid.length;
        int n = grid[0].length;
        List<Integer> arr = new ArrayList<>();
        for(int[] a : grid)
            for(int x : a)
                arr.add(x);

        k = k % (n * m);
        reverseList(arr,0,arr.size()-1);
        reverseList(arr,0,k-1);
        reverseList(arr,k,arr.size()-1);
        
        System.out.println(arr);
        List<List<Integer>> sol = new ArrayList<>();
        for(int i=0;i<m;i++){
            List<Integer> tmp = new ArrayList<>();
            for(int j=0;j<n;j++)
                tmp.add(arr.get(i*n+j));
            sol.add(tmp);
        }

        return sol;    
    }   
}