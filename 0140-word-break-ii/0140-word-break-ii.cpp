class Solution {
private:
    void helper(int i, string& s, string curr, vector<string>& ans, unordered_set<string>& st) {
        int n = s.size();
        if(i == n){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        string temp;
        for(int j=i;j<n;j++) {
            temp+=s[j];
            if(st.count(temp)) {
                helper(j+1,s,curr+temp+' ',ans,st);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto&x : wordDict) {
            st.insert(x);
        }
        vector<string> ans;
        helper(0,s,"",ans,st);
        return ans;
    }
};