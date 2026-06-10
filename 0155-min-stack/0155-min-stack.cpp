class MinStack {
public:
    vector<int> px;
    vector<int> arr;
    MinStack() {
        
    }
    
    void push(int value){
        arr.push_back(value);
        if(!px.empty())
            px.push_back(min(*(px.rbegin()),value));
        else
            px.push_back(value);
    }
    
    void pop(){
        arr.pop_back();
        px.pop_back();
    }
    
    int top() {
        return *(arr.rbegin());
    }
    
    int getMin() {
        return *(px.rbegin());
    }
};
