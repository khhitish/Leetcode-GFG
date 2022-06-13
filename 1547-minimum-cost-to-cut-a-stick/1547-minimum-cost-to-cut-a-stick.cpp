class Solution
{
    private:
        int helper(int i, int j, vector<int> &cuts, vector<vector< int>> &dp)
        {
            if (i == j - 1) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            int ans = 1e9;
            for (int k = i + 1; k < j; k++)
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
            // vector<vector < int>> dp(m, vector<int> (m, -1));
            // return helper(0, m - 1, cuts, dp);
            
            vector<vector<int>> dp(m, vector<int> (m,0));
            for(int i=m-1;i>=0;i--)
            {
                for(int j=i+1; j<=m-1;j++)
                {
                    if(i==j-1) dp[i][j]=0; // base case
                    else
                    {
                        int ans=1e9;
                        for(int k=i+1;k<j;k++)
                        {
                            int currcost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                            ans=min(ans,currcost);
                        }
                        dp[i][j]=ans;
                    }
                }
            }
            return dp[0][m-1];
        }
};