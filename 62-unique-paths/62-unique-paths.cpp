class Solution {
private:
    // maths
    int ncr(int a, int b)
    {
        if(a-b < b)b=a-b;
        vector<long long> dp(b+1,0);
        dp[0]=1;
        for(int i=1;i<=a;i++)
        {
            for(int j=min(i,b);j>0;j--)
            {
                dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[b];
    }
    // memoization
    // int helper(int i, int j, vector<vector<int>>& dp)
    // {
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up=helper(i-1,j,dp);
    //     int left=helper(i,j-1,dp);
    //     return dp[i][j]=up+left;
    // }
public:
    int uniquePaths(int m, int n) {
        // memoization
        // vector<vector<int>> dp(m, vector<int> (n,-1));
        // return helper(m-1,n-1,dp);
        
        // tabulation
        // vector<vector<int>> dp(m, vector<int>(n,0));
        // dp[0][0]=1;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0)continue;
        //         int up = i>0 ? dp[i-1][j] : 0;
        //         int left = j>0 ? dp[i][j-1] : 0;
        //         dp[i][j]=up + left;
        //     }
        // }
        // return dp[m-1][n-1];
        
        // space optimized tabulation
        // vector<int> dp(n,0);
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0)
        //         {
        //             dp[j]=1;
        //             continue;
        //         }
        //         if(j>0)dp[j]+=dp[j-1];
        //     }
        // }
        // return dp[n-1];
        
        // mathematical method
        // if we go m-1 times down and n-1 times right in any order we will definitely reach our destination, means any unique permuation of m-1 downs and n-1 rightd will give us a unique path so just calculate the number of unique permutaions: {(m-1+n-1)!/(m-1)! *(n-1)!}, this is the formula
        // same as m+n-2 C n-1 or m+n-2 C m-1 which we can easily calculate
        int a = m+n-2;
        int b = m-1;
        return ncr(a,b);
    }
};