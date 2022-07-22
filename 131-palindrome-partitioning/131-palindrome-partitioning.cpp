class Solution {
private:
    
    bool ispalindrome(string& s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    void helper(int ind, int last_ind, string &s, vector<string>& temp, vector<vector<string>>& ans)
    {
        if(ind==s.size())
        {
            if(last_ind==ind)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(ispalindrome(s,last_ind,ind)==true)
        {
            string word = s.substr(last_ind,ind-last_ind+1);
            temp.push_back(word);
            helper(ind+1,ind+1,s,temp,ans);
            temp.pop_back();
        }
        helper(ind+1,last_ind,s,temp,ans);
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        helper(0,0,s,temp,ans);
        return ans;
    }
};