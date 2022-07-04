class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> dp(n,1);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1]) dp[i]=dp[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                if(dp[i]<=dp[i+1]) dp[i]=dp[i+1]+1;
            }
            ans+=dp[i];
        }
        ans+=dp[n-1];
        return ans;
    }
};