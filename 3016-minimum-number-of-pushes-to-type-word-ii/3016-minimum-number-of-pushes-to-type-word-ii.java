class Solution {
    public int minimumPushes(String word){
        HashMap<Character,Integer> mp = new HashMap<>();
        for(char c : word.toCharArray())
            mp.put(c,mp.getOrDefault(c,0)+1);

        PriorityQueue<List> pq = new PriorityQueue<>((l1,l2) -> Integer.compare((Integer)l2.get(0),(Integer)l1.get(0)));


        for(Map.Entry<Character,Integer> entry : mp.entrySet())
            pq.add(Arrays.asList(entry.getValue(),entry.getKey()));

        int sol = 0;
        int cnt = 0;
        while(!pq.isEmpty()){
            List l = pq.poll();
            sol += (Integer)l.get(0) * ((cnt / 8) + 1);
            cnt += 1;
        }

        return sol;
    }
}