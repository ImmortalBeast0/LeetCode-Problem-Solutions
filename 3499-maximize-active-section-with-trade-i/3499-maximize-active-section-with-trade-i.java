class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        int cnt = 0;
        ArrayList<Integer> zero_blocks = new ArrayList<>();
        int ones = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == '0')
                cnt += 1;
            else{
                ones += 1;
                if(cnt > 0)
                    zero_blocks.add(cnt);
                cnt = 0;
            }
        }
        if(cnt > 0)
            zero_blocks.add(cnt);
        int zblock = 0;
        for(int i=0;i<zero_blocks.size()-1;i++)
            zblock = Math.max(zblock,zero_blocks.get(i)+zero_blocks.get(i+1));

        return ones + zblock;
    }
}