class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1;i<h.size();i++)
        {
            int curr=h[i] - h[i-1];
            if(curr<0) continue;
            pq.push(curr);
            int temp=0;
            if(pq.size()>l)
            {
                temp=pq.top();
                pq.pop();
            }
            b-=temp;
            if(b<0)
            {
                return i-1;
            }
        }
        return h.size()-1;
    }
};