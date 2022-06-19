class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto &x : s) mp[x]++;
        priority_queue<pair<int,char>> pq;
        for(auto&x : mp)
        {
            pq.push({x.second,x.first});
        }
        string ans;
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int freq=x.first;
            char c=x.second;
            while(freq--)ans+=c;
        }
        return ans;
    }
};