class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(auto&x : num) {
            while(!ans.empty() && ans.back() > x && k>0) {
                ans.pop_back();
                k--;
            }
            if(!(ans.empty() && x == '0'))ans+=x;
        }
        while(k-- && !ans.empty()) ans.pop_back();
        if(ans.empty()) ans+='0';
        return ans;
    }
};