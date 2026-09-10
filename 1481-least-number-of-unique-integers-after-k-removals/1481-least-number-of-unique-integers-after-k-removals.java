class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->Integer.compare(a[0],b[0]));
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int x : arr)
            mp.put(x,mp.getOrDefault(x,0)+1);
        
        for(int key : mp.keySet())
            pq.add(new int[]{mp.get(key),key});

        while(k-- > 0){
            int[] t = pq.poll();
            t[0] -= 1;
            if(t[0] > 0)
                pq.add(t);
        }

        return pq.size();
    }
}