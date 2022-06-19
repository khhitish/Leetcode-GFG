class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(auto&x : points)
        {
            int dist =x[0]*x[0] + x[1]*x[1];
            pq.push({dist, x[0], x[1]});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};