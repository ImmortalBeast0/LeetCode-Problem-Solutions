class Solution {
    int N;
    int[] BIT;
    
    void add(int i ,int x){
        while(i < N){
            BIT[i] += x;
            i += i & (-i);
        }
    }

    int get(int i){
        int sum = 0;
        while(i > 0){
            sum += BIT[i];
            i -= i & (-i);
        }
        return sum;
    }

    int get(int l ,int r){
        return get(r) - get(l-1);
    }

    int n;
    int[] arr;
    public List<Integer> countOfPeaks(int[] nums, int[][] queries){

        n = nums.length;
        arr = new int[n];
        N = (int)1e6;
        BIT = new int[N];
        for(int i=1;i<n-1;i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
                arr[i] = 1;
        }

        for(int i=0;i<n;i++){
            if(arr[i] == 1)
                add(i+1,arr[i]);
        }

        List<Integer> sol = new ArrayList<>();
        for(int[] q : queries){
            if(q[0] == 1){
                int l = q[1] ,r = q[2];
                if(r - l + 1 < 3)
                    sol.add(0);
                else
                    sol.add(get(l+1+1,r-1+1));
            }else{
                int idx = q[1];
                int val = q[2];
                nums[idx] = val;
                for(int d=-1;d<=1;d++){
                    int i = idx + d;
                    if(i < 0 && i >= n) continue;
                    if(i+1 < n && i-1 >= 0){
                        if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                            if(arr[i] != 1){
                                arr[i] = 1;
                                add(i+1,1);
                            }
                        }else{
                            if(arr[i] != 0){
                                arr[i] = 0;
                                add(i+1,-1);
                            }
                        }
                    }
                }
            }
        }

        return sol;
    }
}