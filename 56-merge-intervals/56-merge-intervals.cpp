class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start= intervals[0][0], end=intervals[0][1];
        vector<vector<int>> res;
        for(auto&x : intervals)
        {
            if(x[0]<=end)
            {
                end=max(end,x[1]);
            }
            else
            {
                res.push_back({start,end});
                start=x[0], end=x[1];
            }
        }
        res.push_back({start,end});
        return res;
    }
};