

class Solution {
    public int[] sortByBits(int[] arr) {
        List<Integer> list = new ArrayList<>();
        for(int x : arr)
            list.add(x);


        list.sort((x,y) -> {
            int cnt1 = Integer.bitCount(x);
            int cnt2 = Integer.bitCount(y);
            if(cnt1 < cnt2)
                return -1;
            else if(cnt1 == cnt2)
                return x - y;
            else
                return 1;     
        });
    

        int n = list.size();
        int[] ans = new int[n];
        for(int i=0;i<n;i++)
            ans[i] = list.get(i);

        return ans;
    }
}   