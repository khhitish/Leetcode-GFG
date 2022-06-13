class Solution
{
    // https://youtu.be/auS1fynpnjo
    public:
        int countSquares(vector<vector < int>> &matrix)
        {
            int m = matrix.size(), n = matrix[0].size();
           	// tabulation
           	// vector<vector < int>> dp(m, vector<int> (n));
           	// int ans = 0;
           	// for (int i = 0; i < m; i++)
           	// {
           	//     for (int j = 0; j < n; j++)
           	//     {
           	//         if (i == 0 || j == 0 || matrix[i][j] == 0)
           	//         {
           	//             dp[i][j] = matrix[i][j];
           	//         }
           	//         else
           	//         {
           	//             dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
           	//         }
           	//         ans += dp[i][j];
           	//     }
           	// }
           	// return ans;

           	// space optimised tabulation
           	// vector<int> dp(n);
           	// int prev = 0;
           	// int ans = 0;
           	// for (int i = 0; i < m; i++)
           	// {
           	//     for (int j = 0; j < n; j++)
           	//     {
           	//         int temp = dp[j];
           	//         if (i == 0 || j == 0 || matrix[i][j] == 0)
           	//         {
           	//             dp[j] = matrix[i][j];
           	//         }
           	//         else
           	//         {
           	//             dp[j] = min(dp[j], min(prev, dp[j - 1])) + 1;
           	//         }
           	//         ans += dp[j];
           	//         prev = temp;
           	//     }
           	// }
           	// return ans;

           	// reusing the matrix constant auxiliary space
            int ans = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 || j == 0 || matrix[i][j] == 0)
                    {
                        matrix[i][j] = matrix[i][j];
                    }
                    else
                    {
                        matrix[i][j] = min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i][j - 1])) + 1;
                    }
                    ans += matrix[i][j];
                }
            }
            return ans;
        }
};