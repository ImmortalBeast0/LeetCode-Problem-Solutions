class Solution {

    int rec(int pos ,int[] freq){
        if(pos >= 3)
            return 1;

        int ans = 0;
        for(int key = 0 ;key < 10 ;key += 1){
            if(freq[key] > 0){
                freq[key] -= 1;
                if(pos == 2 && key % 2 == 0)
                    ans += rec(pos+1,freq);
                if(pos == 0 && key != 0)
                    ans += rec(pos+1,freq);
                if(pos == 1)
                    ans += rec(pos+1,freq);
                freq[key] += 1;
            }
        }

        return ans;
    }

    public int totalNumbers(int[] digits){

        int freq[] = new int[10];
        for(int x : digits)
            freq[x] += 1;

        return rec(0,freq);
    }
}