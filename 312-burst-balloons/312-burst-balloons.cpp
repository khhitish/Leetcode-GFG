class Solution
{
    // https://youtu.be/Yz4LlDSlkns
    private:
        int helper(int i, int j, vector<int> &nums, vector<vector< int>> &dp)
        {
            if (i > j) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            int ans = -1e9;
            for (int k = i; k <= j; k++)
            {
                int curr = nums[i - 1] *nums[k] *nums[j + 1] + helper(i, k - 1, nums, dp) + helper(k + 1, j, nums, dp);
                ans = max(ans, curr);
            }
            return dp[i][j] = ans;
        }
    public:
        int maxCoins(vector<int> &nums)
        {
            nums.push_back(1);
            nums.insert(nums.begin(), 1);
            int n = nums.size();

           	// memoiation
           	// vector<vector < int>> dp(n, vector<int> (n, -1));
           	// return helper(1, n - 2, nums, dp);	// 1 refers to nums[0], n-2 refers to nums[n-1] since 1 was inserted at the front and at the back

           	// tabulation
            vector<vector < int>> dp(n, vector<int> (n, 0));
            for(int i=n-2;i>=1;i--)
            {
                for(int j=i;j<=n-2;j++)
                {
                    int ans=-1e9;
                    for(int k=i;k<=j;k++)
                    {
                        int curr=nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                        ans=max(ans,curr);
                    }
                    dp[i][j]=ans;
                        
                }
            }
            return dp[1][n-2];
        }
};