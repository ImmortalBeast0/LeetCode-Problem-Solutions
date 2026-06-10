class MinStack {
public:
    map<int,int> mp;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int value){
        st.push(value);
        mp[value]++;
    }
    
    void pop(){
        int value = st.top();
        st.pop();
        mp[value]--;
        if(mp[value] == 0)
            mp.erase(value);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mp.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */