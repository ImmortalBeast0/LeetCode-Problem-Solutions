class StockSpanner {
    
    ArrayList<Integer> arr;
    Deque<Integer> st;

    public StockSpanner() {
        arr = new ArrayList<>();
        st = new ArrayDeque<>();
    }
    
    public int next(int price){

        arr.add(price);

        while(!st.isEmpty() && arr.get(st.peek()) <= price)
            st.pop();

        if(!st.isEmpty()){
            int j = st.peek();
            st.push(arr.size() - 1);
            return (arr.size() - 1) - (j + 1) + 1;
        }else{
            st.push(arr.size() - 1);
            return arr.size();
        }

        
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */