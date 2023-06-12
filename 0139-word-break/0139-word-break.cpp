class Solution {
private:
    bool helper(int i, string& s, unordered_set<string>& st, vector<int>& dp) {
        int n = s.size();
        if(i == n) return true;
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i;j<n;j++) {
            temp+=s[j];
            if(st.count(temp)) {
                if(helper(j+1,s,st,dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.size();
        vector<int> dp(n, -1);
        for(auto&x : wordDict) {
            st.insert(x);
        }
        return helper(0,s,st,dp);
    }
};