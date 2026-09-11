class Solution {
    List<Integer> ans = new ArrayList<>();
    int x = 0;
    int rec(int pos ,int[] freq){
         if(pos >= 3){
            ans.add(x);
            return 1;
        }

        int ans = 0;
        for(int key = 0 ;key < 10 ;key += 1){
            if(freq[key] > 0){
                freq[key] -= 1;
                x *= 10;
                x += key;
                if(pos == 2 && key % 2 == 0)
                    ans += rec(pos+1,freq);
                if(pos == 0 && key != 0)
                    ans += rec(pos+1,freq);
                if(pos == 1)
                    ans += rec(pos+1,freq);
                freq[key] += 1;      
                x /= 10;
            }
        }

        return ans;
    }

    public int[] findEvenNumbers(int[] digits) {
        int[] freq = new int[11];
        for(int x : digits)
            freq[x] += 1;
        rec(0,freq);
        int[] sol = new int[ans.size()];
        int i = 0;
        for(int x : ans)
            sol[i++] = x;
        return sol;
    }
}