class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        long long mod = 1e9+7;
        for(auto &x : roads)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int curr = p.second;
            long long d = p.first;
            for(auto &x : adj[curr])
            {
                
                int node = x.first;
                int wt = x.second;
                if(d + wt < dist[node])
                {
                    dist[node] = d + wt;
                    ways[node]=ways[curr];
                    pq.push({dist[node],node});
                }
                else if(d + wt == dist[node])
                {
                    ways[node]= (ways[node]  + ways[curr])%mod;
                }
            }
        }
        return ways[n-1];
    }
};