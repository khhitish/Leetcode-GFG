class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int> v(26,0);
        for(auto&x : a)
        {
            v[x-'a']++;
        }
        for(auto&x : b)
        {
            v[x-'a']--;
        }
        for(auto&x : v)
        {
            if(x>0) return false;
        }
        return true;
    }
};