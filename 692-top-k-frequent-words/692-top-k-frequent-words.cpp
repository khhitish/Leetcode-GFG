struct compare 
{
    bool operator()(pair<int,string> &p1, pair<int,string> &p2)
    {
        if(p1.first>p2.first) return true;
        else if(p1.first<p2.first) return false;
        else
        {
            return p2>p1;
        }
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto&x : words)
        {
            mp[x]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> pq;
        for(auto&x : mp)
        {
            pq.push({x.second,x.first});
            if(pq.size()>k)pq.pop();
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