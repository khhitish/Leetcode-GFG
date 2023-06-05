class Solution {
private:
    bool isPalindrome(string& s, int start, int end)
    {
        while(start<end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    void helper(int i, string& s, vector<string>& curr, vector<vector<string>>& ans)
    {
        if(i == s.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int j = i;j<s.size();j++)
        {
            if(isPalindrome(s,i,j))
            {
                string temp = s.substr(i,j-i+1);
                curr.push_back(temp);
                helper(j+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0,s,curr,ans);
        return ans;
    }
};