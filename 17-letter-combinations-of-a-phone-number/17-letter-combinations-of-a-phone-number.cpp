class Solution {
private:
    void helper(int i, string digits, string& temp, vector<string>& ans, vector<string>& mappings)
    {
        if(i==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        int curr = digits[i] - '0';
        for(auto &x : mappings[curr])
        {
            temp.push_back(x);
            helper(i+1,digits,temp,ans,mappings);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string> ans;
        if(digits.size()==0) return ans;
        vector<string> mappings = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
        helper(0,digits,temp,ans,mappings);
        return ans;
    }
};