class Solution
{
    public:
        string reverseWords(string s)
        {
            string ans;
            int i = 0, n = s.size();
            
            //removing extra spaces between words,before words, after words
            while (i < n)
            {
                while (i < n && s[i] == ' ') i++;
                while (i < n && s[i] != ' ')
                {
                    ans += s[i];
                    i++;
                }
                ans += ' ';
               	//cout<<ans<<endl;
            }
            while (ans.back() == ' ') ans.pop_back();
            //reversing entire string and then reversing each word
            reverse(ans.begin(), ans.end());
            int start = 0;
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] == ' ')
                {
                    reverse(ans.begin() + start, ans.begin() + i);
                    start = i + 1;
                }
            }
            reverse(ans.begin() + start, ans.end());
            return ans;
        }
};