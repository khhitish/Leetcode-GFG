class MedianFinder {
private:
    double median;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(num>median)
        {
            minheap.push(num);
        }
        else
        {
            maxheap.push(num);
        }
        int s1=maxheap.size(), s2=minheap.size();
        if(s1-s2>1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            s2++;s1--;
        }
        else if(s2-s1>1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
            s2--; s1++;
        }
        if(s1==s2)
        {
            median= (minheap.top() + maxheap.top())/(2.0);
        }
        else if(s1>s2)
        {
            median=maxheap.top();
        }
        else
        {
            median=minheap.top();
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */