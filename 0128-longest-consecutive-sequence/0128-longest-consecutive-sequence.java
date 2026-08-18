class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> exist = new HashSet<>();
        for(int x : nums)
            exist.add(x);

        HashMap<Integer,Boolean> vis = new HashMap<>();
        int n  = nums.length;
        int cnt = 0; // xth Component explore 
        int j = 0; //this is a pointer for arr 
        int[] arr = new int[n];
        Arrays.fill(arr,-1);
        for(int i=0;i<n;i++){

            if(!vis.containsKey(nums[i])){
                // bfs 
                
                Deque<Integer> q = new ArrayDeque<>(); 
                q.addFirst(nums[i]);
                vis.put(nums[i],true);
                arr[j++] = cnt;

                while(q.size() > 0){
                    int x = q.pollFirst();
                    if(exist.contains(x + 1) && !vis.getOrDefault(x + 1,false)){
                        q.addLast(x + 1);
                        vis.put(x + 1,true);
                        arr[j++] = cnt;
                    }
                    if(exist.contains(x - 1) && !vis.getOrDefault(x - 1,false)){
                        q.addLast(x - 1);
                        vis.put(x - 1,true);
                        arr[j++] = cnt;
                    }
                }

                cnt += 1;
            }
                
        }

        int mx = 0;
        int i = 0 ;j = 0;
        System.out.println(Arrays.toString(arr));
        for(;i<arr.length;){
            if(arr[i] == -1)
                break;
            while(j < arr.length && arr[i] == arr[j]){
                mx = Math.max(mx,j - i + 1);
                j += 1;
            }
            i = j;
        }

        return mx;
    }
}