class Solution {
    public int minimumPushes(String word){
        HashMap<Character,Integer> mp = new HashMap<>();
        for(char c : word.toCharArray())
            mp.put(c,mp.getOrDefault(c,0)+1);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(Map.Entry<Character,Integer> entry : mp.entrySet())
            pq.add(-entry.getValue());

        int cnt = 0;
        int sol = 0;
        while(!pq.isEmpty())
            sol += -pq.poll() * (cnt++ / 8 + 1);

        return sol; 
    }
}