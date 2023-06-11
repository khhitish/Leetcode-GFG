class Solution {
private:
    bool helper(int i, int last, string& s, unordered_set<string>& st, vector<vector<int>>& dp) {
        int n = s.size();
        if(i == n) {
            if(last == n) return true;
            return false;
        }
        if(dp[i][last]!=-1) return dp[i][last];
        bool ans = false;
        if(st.count(s.substr(last,i-last+1))) {
            ans|=helper(i+1,i+1,s,st,dp);
        }
        ans|=helper(i+1,last,s,st,dp);
        return dp[i][last] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(auto&x : wordDict) {
            st.insert(x);
        }
        return helper(0,0,s,st,dp);
    }
};