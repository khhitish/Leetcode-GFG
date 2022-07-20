class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans=0;
        while(s.size())
        {
            int ind = s.find(s.back());
            if(ind==s.size()-1)
            {
                ans+=ind/2;
            }
            else
            {
                ans+=ind;
                s.erase(ind,1);
            }
            s.pop_back();
        }
        return ans;
    }
};