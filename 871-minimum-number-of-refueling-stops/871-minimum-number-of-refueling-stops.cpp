class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
        int maxreach=startFuel;
        int i=0, n=s.size();
        priority_queue<int> pq;
        int cnt=0;
        while(maxreach<target)
        {
            while(i<n && s[i][0]<=maxreach)
            {
                pq.push(s[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            cnt++;
            maxreach+=pq.top();
            pq.pop();
        }
        return cnt;
    }
};