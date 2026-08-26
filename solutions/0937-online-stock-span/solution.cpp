class StockSpanner {
public:
    stack<pair<int, int>>stk;
    int index;
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        int ans = 0;
        index = index+1;
        while(!stk.empty() && stk.top().first <= price) {
            stk.pop();
        }
        ans = index - (stk.empty() ? - 1 : stk.top().second);
        stk.push({price, index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
