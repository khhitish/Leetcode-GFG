class Solution {
public:
    int minDistance(string s, string t) {
        int m=s.size(), n=t.size();
        vector<int> dp(n+1,0);
        int prev=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int temp=dp[j];
                if(s[i-1]==t[j-1])
                {
                    dp[j]=1 + prev;
                }
                else
                {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev=temp;
            }
            prev=0;
        }
        return m+n-2*dp[n];
    }
};