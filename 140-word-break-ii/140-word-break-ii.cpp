class Solution
{
    private:
        void helper(int i, int ls, unordered_set<string> &st, string &s, string &temp, vector<string> &ans)
        {
            if (i == s.size() - 1)
            {
                if (st.count(s.substr(ls, i - ls + 1)) != 0)
                {
                    temp += s[i];
                    ans.push_back(temp);
                    temp.pop_back();
                }
                return;
            }
            temp += s[i];
           	//cout<<temp<<endl;
            if (st.count(s.substr(ls, i - ls + 1)) != 0)
            {
                temp += ' ';
                helper(i + 1, i + 1, st, s, temp, ans);
                temp.pop_back();
            }
            helper(i + 1, ls, st, s, temp, ans);
            temp.pop_back();
        }
    public:
        vector<string> wordBreak(string s, vector<string> &dictionary)
        {
            unordered_set<string> st;
            for (auto &x: dictionary)
            {
                st.insert(x);
            }
            string temp;
            vector<string> ans;
            helper(0, 0, st, s, temp, ans);
            return ans;
        }
};