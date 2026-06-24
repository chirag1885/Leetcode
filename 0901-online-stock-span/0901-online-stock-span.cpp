class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> s1;
    int next(int price) {
        int span=1;
        while(!s1.empty() && s1.top().first<=price){
            span+=s1.top().second;
            s1.pop();
        }
        s1.push({price , span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */