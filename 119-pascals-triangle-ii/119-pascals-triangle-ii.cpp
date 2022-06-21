class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> dp(r+1,0);
        dp[0]=1;
        for(int i=1;i<=r;i++)
        {
            for(int j=r;j>0;j--)
            {
                dp[j] = (dp[j] + dp[j-1]);
            }
        }
        return dp;
    }
};