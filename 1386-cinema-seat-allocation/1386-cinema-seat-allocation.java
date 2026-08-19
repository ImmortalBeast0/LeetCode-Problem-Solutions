class Solution {
    public int maxNumberOfFamilies(int n, int[][] res){
        
        int sol = n * 2;
        Arrays.sort(res,(a,b) -> Integer.compare(a[0],b[0]));

        // 
        // {1 ,2 ,3 ,4} ,{3 ,4 ,5 ,6} ,{5 ,6 ,7 ,8}
        //

        for(int i=0;i<res.length;){
            int j = i;
            int arr[] = new int[10];
            while(j < res.length && res[i][0] == res[j][0]){
                arr[res[j][1] - 1] = 1;
                j += 1;
            }
            i = j;
            for(int k=1;k<10;k++)
                arr[k] += arr[k - 1];

            int g1 = arr[4] - arr[0];
            int g2 = arr[6] - arr[2];
            int g3 = arr[8] - arr[4];

            if(g1 != 0 && g2 != 0 && g3 != 0)
                sol -= 2;
            else if(g1 != 0 || g3 != 0)
                sol -= 1;
        }

        return sol;
    }
}