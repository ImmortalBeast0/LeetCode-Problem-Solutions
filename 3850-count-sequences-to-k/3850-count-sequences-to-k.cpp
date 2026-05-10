class Solution {
public:
    int n;
    int need_two ,need_three ,need_five;
    map<string,int> dp;
    int rec(int i ,int two ,int three ,int five ,vector<int>& nums){
        if(i >= n)
            return two == need_two && three == need_three && five == need_five;

        string s = to_string(i) + "#" + to_string(two) + "#" + to_string(three) + "#" + to_string(five) + "#";
        if(dp.find(s) != dp.end())
            return dp[s];

        int ans = 0;
        ans += rec(i+1,two,three,five,nums);

        int x = nums[i] ,cnt2 = 0 ,cnt3 = 0 ,cnt5 = 0;
        if(x == 2 || x == 4) cnt2 += (x / 2);
        if(x == 3) cnt3 += 1;
        if(x == 5) cnt5 += 1;
        if(x == 6) cnt2 += 1 ,cnt3 += 1;

        ans += rec(i+1,two+cnt2,three+cnt3,five+cnt5,nums);
        ans += rec(i+1,two-cnt2,three-cnt3,five-cnt5,nums);

    
        return dp[s] = ans;
    }

    int countSequences(vector<int>& nums, long long k) {
        need_two = 0,need_three = 0,need_five = 0;
        n = nums.size();
        while(k % 2 == 0){
            need_two += 1;
            k /= 2;
        }
        while(k % 3 == 0){
            need_three += 1;
            k /= 3;
        }
        while(k % 5 == 0){
            need_five += 1;
            k /= 5;
        }
        if(k > 1)
            return 0;
        return rec(0,0,0,0,nums);
    }
};