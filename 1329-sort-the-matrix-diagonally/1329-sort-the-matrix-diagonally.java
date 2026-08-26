class Solution {
    public int[][] diagonalSort(int[][] mat) {
        
        int m = mat.length;
        int n = mat[0].length;

        for(int J=0;J<n;J++){

            int i = 0;
            int j = J;
            List<Integer> a = new ArrayList<>();
            while(i < m && j < n)
                a.add(mat[i++][j++]);
            
            Collections.sort(a);

            i = 0;
            j = J;
            int k = 0;
            while(i < m && j < n){
                mat[i++][j++] = a.get(k++);
            }
        }

        for(int I=0;I<m;I++){

            int i = I;
            int j = 0;
            List<Integer> a = new ArrayList<>();
            while(i < m && j < n)
                a.add(mat[i++][j++]);
            
            Collections.sort(a);

            i = I;
            j = 0;
            int k = 0;
            while(i < m && j < n){
                mat[i++][j++] = a.get(k++);
            }
        }

        return mat;
    }
}