class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // set solution
        unordered_set<string> st;
        for(auto&x : words)st.insert(x);
        for(auto&s : words)
        {
            for(int i=1;i<s.size();i++)
            {
                st.erase(s.substr(i));
            }
        }
        int ans=0;
        for(auto &it: st)
        {
            ans+=it.size();
            ans++;
        }
        return ans;
    }
};