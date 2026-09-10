class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        // in this code logic is 
        // remove the smallest frequency element first(as much we can) ,to reduce the unique elements in array

        //so then calculate the frequency of the frequency array 
        // now we have the freq[freq] ,lets say ,1 freq 5 elements we can delete this element at once 
        // if we can .... else remove rest of that 

        int freqOfFreq[] = new int[(int)1e5 + 1]; // it much larget ,but it only required less than this

        HashMap<Integer,Integer> mp = new HashMap<>();
        int cnt = 0; // this holds number of uniques in given array
        for(int x : arr){
            Integer f = mp.get(x);
            if(f == null){
                freqOfFreq[1] += 1;
                mp.put(x,1);
                cnt += 1;
            }else{
                freqOfFreq[f] -= 1;
                mp.put(x,f+1);
                freqOfFreq[f+1] += 1;
            }
        }

        int i = 1;
        while(k > 0){
            if(freqOfFreq[i] * i <= k){
                k -= freqOfFreq[i] * i;
                cnt -= freqOfFreq[i];
            }else{
                int rem_rq = k / i;
                cnt -= rem_rq;
                break;
            }
            i += 1;
        }

        return cnt;
    }
}