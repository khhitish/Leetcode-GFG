class Solution {
private:
    static bool compare(pair<int,int> &p1, pair<int,int> &p2)
    {
        if(p1.first<p2.first) return true;
        else if(p1.first>p2.first) return false;
        else
        {
            return p1.second>p2.second;
        }
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>> v;
        unordered_map<int,int> mp;
        for(auto&x : nums)mp[x]++;
        for(auto&x : mp)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(), v.end(), compare);
        vector<int> ans;
        for(auto&x : v)
        {
            int freq=x.first, n=x.second;
            while(freq--)ans.push_back(n);
        }
        return ans;
    }
};