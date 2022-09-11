class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>> pq;
        long ans=0,sum=0;
        for(auto&x : v)
        {
            pq.push(x.second);
            sum+=x.second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*x.first);
        }
        return ans%(int)(1e9+7);
    }
};