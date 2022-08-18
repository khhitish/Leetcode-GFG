class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for(auto&x : arr)
        {
            m[x]++;
        }
        vector<int> freq;
        for(auto&x : m)
        {
            freq.push_back(x.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int req = n/2, ans=0;
        for(int i=0;i<freq.size() && req>0;i++)
        {
            req-=freq[i];
            ans++;
        }
        return ans;
    }
};