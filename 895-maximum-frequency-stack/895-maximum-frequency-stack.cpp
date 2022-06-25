class FreqStack {
private:
    vector<stack<int>> v;
    unordered_map<int,int> freq;
public:
    FreqStack() {
        stack<int> temp;
        v.push_back(temp);
    }
    
    void push(int val) {
        freq[val]++;
        int index = freq[val];
        int curr_size = v.size();
        if(index > curr_size - 1)
        {
            stack<int> s;
            s.push(val);
            v.push_back(s);
        }
        else
        {
            v[index].push(val);
        }
    }
    
    int pop() {
        int val = v.back().top();
        freq[val]--;
        v.back().pop();
        if(v.back().empty()==true)
        {
            v.pop_back();
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */