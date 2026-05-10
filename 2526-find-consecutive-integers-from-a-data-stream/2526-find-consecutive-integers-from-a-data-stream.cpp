class DataStream {
public:
    map<int,int> mp;
    queue<int> q;
    int value;
    int k;
    DataStream(int value_, int k_){
        value = value_;
        k = k_;
    }
    
    bool consec(int num){

        mp[num]++;
        q.push(num);
        if(q.size() > k){
            int x = q.front();
            q.pop();
            mp[x]--;
        }

        if(q.size() < k)
            return false;

        return mp[value] == k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */