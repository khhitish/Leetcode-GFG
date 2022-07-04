class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(auto&x : num)
        {
            while(!s.empty() && k>0 && s.top()>x)
            {
                k--;
                s.pop();
            }
            s.push(x);
        }
        while(k>0 && !s.empty())
        {
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string ans;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        while(ans.size()>0 && ans.back()=='0')ans.pop_back();
        if(ans.size()==0) return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};