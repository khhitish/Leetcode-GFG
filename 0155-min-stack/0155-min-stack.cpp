class MinStack {
private:
    stack<long long> s;
    long long mini;
public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val);
            mini = val;
        }
        else if(val>= mini) s.push(val);
        else {
            long long newMini = val;
            s.push(val - mini + val); // negative + val, meaning stored num will be less than the new minimum i.e. x hence we will know and extract the old minimum from it.
            mini = newMini;
        }
    }
    
    void pop() {
        long long val = s.top();
        s.pop();
        if(val < mini) {
            long long oldMini = 2*mini - val;
            val = mini;
            mini = oldMini;
        }
        return;
    }
    
    int top() {
        long long val = s.top();
        if(val < mini) {
            val = mini;
        }
        return val;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */