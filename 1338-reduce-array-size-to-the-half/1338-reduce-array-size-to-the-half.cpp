class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for(auto&x : arr)
        {
            m[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto&x : m)
        {
            pq.push({x.second,x.first});
        }
        int req = n/2;
        int ans = 0;
        while(req>0)
        {
            req-=pq.top().first;
            pq.pop();
            ans++;
        }
        return ans;
    }
};