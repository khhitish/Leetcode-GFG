class StockSpanner {
private:
    stack<int> s;
    vector<int> v;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int i = v.size()-1;
        while(!s.empty() && v[s.top()]<=v[i]) s.pop();
        int ans;
        if(s.empty()) ans=i+1;
        else ans=i-s.top();
        s.push(i);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */