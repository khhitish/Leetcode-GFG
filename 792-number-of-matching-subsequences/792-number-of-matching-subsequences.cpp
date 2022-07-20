class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]].push_back(i);
        }
        int ans=0;
        for(auto&x : words)
        {
            int prev=-1;
            int i;
            for(i=0;i<x.size();i++)
            {
                char c=x[i];
                auto it = upper_bound(m[c].begin(), m[c].end(), prev);
                if(it==m[c].end())break;
                prev= *it;
            }
            if(i==x.size())ans++;
        }
        return ans;
    }
};