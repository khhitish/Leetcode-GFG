class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto &s : words)
        {
            unordered_map<char,char> mpp;
            unordered_set<char> st;
            bool flag = true;
            for(int i =0;i<s.size();i++)
            {
                if(mpp.count(pattern[i])==0)
                {
                    if(st.count(s[i])!=0)
                    {
                        flag=false;
                        break;
                    }
                    else
                    {
                        mpp[pattern[i]] = s[i];
                        st.insert(s[i]);
                    }
                }
                else
                {
                    if(mpp[pattern[i]]!=s[i])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};