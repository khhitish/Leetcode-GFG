struct compare{
    bool operator()(pair<int,string>& p1, pair<int,string>& p2)
    {
        if(p2.first<p1.first) return true;
        else if(p2.first > p1.first) return false;
        else
        {
            return p2.second > p1.second;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        for(auto&x : words)
        {
            mpp[x]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> pq;
        for(auto &x : mpp)
        {
            pq.push({x.second,x.first});
            if(pq.size() > k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};