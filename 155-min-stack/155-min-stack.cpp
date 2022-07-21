class MinStack {
private:
    stack<long long> s;
    long long minimum;
public:
    MinStack() {
        minimum=INT_MAX;
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            minimum=val;
        }
        else if(val>=minimum)s.push(val);
        else
        {
            int new_min=val;
            s.push(val + (val-minimum));
            minimum=new_min;
        }
    }
    
    void pop() {
        if(s.top()>=minimum)s.pop();
        else
        {
            int prev_min = minimum + (minimum-s.top());
            s.pop();
            minimum=prev_min;
        }
    }
    
    int top() {
        if(s.top()>=minimum)return s.top();
        else return minimum;
    }
    
    int getMin() {
        return minimum;
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