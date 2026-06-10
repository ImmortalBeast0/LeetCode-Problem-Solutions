import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class Main{
}

class SparseTable{
    static int K = 25;
    int[][] min ,max;

    SparseTable(int[] nums){
        int n = nums.length;
        min = new int[K+1][n+1];
        max = new int[K+1][n+1];
        for(int i=0;i<n;i++){
            min[0][i] = nums[i];
            max[0][i] = nums[i];
        }

        for(int i=1;i<=K;i++){
            for(int j=0;j + (1 << (i-1)) <= n;j++){
                min[i][j] = min(min[i-1][j],min[i-1][j + (1 << (i-1))]);
                max[i][j] = max(max[i-1][j],max[i-1][j + (1 << (i-1))]);
            }
        }

    }

    int rangeQuery(int l ,int r){

        int mn = (int)1e10;
        int mx = -(int)1e10;

        for(int i=K;i>=0;i--){
            int ln = r - l + 1;
            if(ln >= (1 << i)){
                mn = min(mn,min[i][l]);
                mx = max(mx,max[i][l]);
                l += (1 << i);
            }
        }

        return mx - mn;
    }

    int min(int a ,int b){
        if(a < b)
            return a;
        return b;
    }

    int max(int a ,int b){
        if(a > b)
            return a;
        return b;
    }
}


class Solution {



    public long maxTotalValue(int[] nums, int k) {

        // l ,n - 1 its the maximum value hold , and the value was monotonically increasing 

        int n = nums.length;
        SparseTable st = new SparseTable(nums);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> b[0] - a[0]);

        for(int l=0;l<n;l++){
            int x = st.rangeQuery(l,n-1);
            int[] tmp = {x,l,n-1};
            pq.add(tmp);
        }

        long sol = 0;
        while(k-- > 0){
            int[] tmp = pq.poll();
            sol += tmp[0];
            int l = tmp[1] ,r = tmp[2];
            if(r-1 >= l){
                tmp[0] = st.rangeQuery(l,r-1);
                tmp[1] = l;
                tmp[2] = r-1;
                pq.add(tmp);
            }
        }

        return sol;
    }
}