class Solution {
public:
    string reorganizeString(string str) {
        vector<int> v(26,0);
        for(auto&x : str)
        {
            v[x-'a']++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++)
        {
            if(v[i]>0)
            {
                pq.push({v[i],'a' + i});
            }
        }
        string ans;
        while(!pq.empty())
        {
            char c1 = pq.top().second;
            int freq1 = pq.top().first;
            pq.pop();
            if(pq.size()==0)
            {
                if(freq1>1) return "";
                ans+=c1;
            }
            else
            {
                char c2 = pq.top().second;
                int freq2 = pq.top().first;
                pq.pop();
                ans+=c1;
                ans+=c2;
                freq1--;
                freq2--;
                if(freq1>0) pq.push({freq1,c1});
                if(freq2>0) pq.push({freq2,c2});
            }
        }
        return ans;
    }
};