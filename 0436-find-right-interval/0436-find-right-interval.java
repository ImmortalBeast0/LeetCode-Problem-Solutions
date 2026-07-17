class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;

        int[][] arr = new int[n][2];

        for(int i=0;i<n;i++){
            arr[i] = new int[]{intervals[i][0],i};
        }

        Arrays.sort(arr,(a,b) -> {
            if(a[0] == b[0])
                return Integer.compare(a[1],b[1]);
            return Integer.compare(a[0],b[0]);
        });


        int[] sol = new int[n];
        for(int i=0;i<n;i++){
            int en = intervals[i][1];
            int ans = -1;
            int lb = 0 ,ub = n - 1;
            while(lb <= ub){
                int mi = (ub - lb)/2 + lb;
                if(arr[mi][0] >= en){
                    ans = arr[mi][1];
                    ub = mi - 1;
                }else
                    lb = mi + 1;
            }

            sol[i] = ans;
        }

        return sol;
    }
}