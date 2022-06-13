class Solution
{
    private:
        int helper(int i, int k, vector<int> &arr, vector<int> &dp)
        {
            int n = arr.size();
            if (i == n) return 0;
            if (dp[i] != -1) return dp[i];
            int ans = -1e9, maxe = arr[i];
            for (int j = i; j < n && j < i + k; j++)
            {
                maxe = max(arr[j], maxe);
                int currans = maxe *(j - i + 1) + helper(j + 1, k, arr, dp);
                ans = max(ans, currans);
            }
            return dp[i] = ans;
        }
    public:
        int maxSumAfterPartitioning(vector<int> &arr, int k)
        {

            int n = arr.size();
            // vector<int> dp(n, -1);
            // return helper(0, k, arr, dp);
            
            
            // tabulation
            vector<int> dp(n+1,0);
            dp[n]=0; // base case;
            for(int i=n-1;i>=0;i--)
            {
                int ans = -1e9, maxe = arr[i];
                for(int j=i;j<n && j<i+k;j++)
                {
                    maxe=max(arr[j],maxe);
                    int currans = maxe *(j - i + 1) + dp[j+1];
                    ans=max(ans,currans);
                }
                dp[i]=ans;
            }
            return dp[0];
        }
};