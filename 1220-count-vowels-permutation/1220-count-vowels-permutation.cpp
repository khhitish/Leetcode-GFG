class Solution {
private:
    int helper(char prev, int ind, int n, unordered_map<char,vector<char>>& mappings, unordered_map<char, vector<int>>& dp)
    {
        if(ind==n) return 1;
        if(dp[prev][ind]!=-1) return dp[prev][ind];
        int mod = 1e9+7;
        int ans = 0;
        for(auto&c : mappings[prev])
        {
            ans = (ans + helper(c,ind+1,n,mappings,dp))%mod;
        }
        return dp[prev][ind]=ans;
    }
public:
    int countVowelPermutation(int n) {
        unordered_map<char,vector<char>> mappings;
        mappings['s'] = {'a', 'e', 'i', 'o', 'u'};
        mappings['a'] = {'e'};
        mappings['e'] = {'a', 'i'};
        mappings['i'] = {'a', 'e', 'o', 'u'};
        mappings['o'] = {'i', 'u'};
        mappings['u'] = {'a'};
        unordered_map<char,vector<int>> dp;
        dp['a'] = vector<int>(n,-1);
        dp['e'] = vector<int>(n,-1);
        dp['i'] = vector<int>(n,-1);
        dp['o'] = vector<int>(n,-1);
        dp['u'] = vector<int>(n,-1);
        dp['s'] = vector<int>(n,-1);
        int ans = 0;
        int mod = 1e9+7;
        return helper('s',0,n,mappings,dp);
    }
};