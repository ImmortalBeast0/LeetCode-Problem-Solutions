class Solution {
    public int majorityElement(int[] nums){
        // Boyer Moore Algorithm 
        //by Candidated votes elemination

        int candidate = -1;
        int vote = 0;

        for(int x : nums){
            if(vote == 0){
                candidate = x;
                vote = 1;
            }else if(candidate == x)
                vote += 1;
            else
                vote -= 1;
        }

        int cnt = 0;
        for(int x : nums){
            if(x == candidate)
                cnt += 1;
        }

        if(cnt > (nums.length ) / 2)
            return candidate;
        return -1;
    }
}