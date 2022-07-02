class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i=0;i<200;i++)
        {
            char letter;
            if(i<strs[0].size()) letter=strs[0][i];
            else return strs[0].substr(0,i);
            for(auto&x : strs)
            {
                if(i>=x.size() || x[i]!=letter)
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};