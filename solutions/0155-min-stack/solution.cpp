class MinStack {
public:
    stack<long long>stk;
    long long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        if(stk.empty()) {
            mini = value;
            stk.push(value);
        }
        else {
            if(value>mini) {
                stk.push(value);
            }
            else {
                stk.push(2LL*value - mini);
                mini = value;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) {
            return;
        }
        long long x = stk.top();
        stk.pop();
        if(x < mini) {
            mini = 2LL*mini - x;
        }
    }
    
    int top() {
        if(stk.empty()) {
            return 0;
        }
        long long x = stk.top();
        if(x < mini) {
            return mini;
        }
        return x;
    }
    
    int getMin() {
        return (long long)mini;
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
