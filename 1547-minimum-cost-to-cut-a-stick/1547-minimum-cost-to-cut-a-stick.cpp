class Solution
{
    private:
        int helper(int i, int j, vector<int> &cuts, vector<vector< int>> &dp)
        {
            if (i == j-1) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            int ans = 1e9;
            for (int k = i+1; k < j; k++)
            {
                int currcost = cuts[j] - cuts[i] + helper(i, k, cuts, dp) + helper(k, j, cuts, dp);
                ans = min(ans, currcost);
            }
            return dp[i][j] = ans;
        }
    public:
        int minCost(int n, vector<int> &cuts)
        {
            cuts.push_back(0);
            cuts.push_back(n);
            int m = cuts.size();
            sort(cuts.begin(), cuts.end());
            vector<vector < int>> dp(m,vector<int> (m, -1));
            return helper(0, m - 1, cuts, dp);
        }
};