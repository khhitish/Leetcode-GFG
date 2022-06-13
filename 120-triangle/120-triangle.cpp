class Solution {
    // https://youtu.be/SrP-PiLSYC0
    // somewhat of a different problem. Since we don't know which column to end at in order to have min path sum, we cannot start recursion from n-1,n-1. still recursion is top down, and here the base case becomes when i==n-1 and tabulation is done in opposite order to recursion always hence started tabulation from bottom  row
private:
    // memoization
//     int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
//     {
//         if(i == triangle.size()-1)
//         {
//             return triangle[i][j];
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         int down = triangle[i][j] + helper(i+1,j,triangle,dp);
//         int dia = triangle[i][j] + helper(i+1,j+1,triangle,dp);
//         return dp[i][j]=min(down,dia);
        
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // memoization
        // vector<vector<int>> dp(n);
        // for(int i=0;i<n;i++)
        // {
        //     dp[i].resize(triangle[i].size(),-1); // we can also declare n*n dp
        // }
        // return helper(0,0,triangle,dp);
        
        // tabulation
        // vector<vector<int>> dp(n, vector<int> (n,0));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=i;j>=0;j--)
        //     {
        //         if(i==n-1) dp[i][j]=triangle[i][j];
        //         else
        //         {
        //             int dia = triangle[i][j] + dp[i+1][j+1];
        //             int down = triangle[i][j] + dp[i+1][j];
        //             dp[i][j]=min(down,dia);
        //         }
        //     }
        // }
        // return dp[0][0];
        
        // space optimized tabulation
        // vector<int> dp(n,0), temp(n,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=i;j>=0;j--)
        //     {
        //         if(i==n-1) temp[j]=triangle[i][j];
        //         else
        //         {
        //             int down = triangle[i][j] + dp[j];
        //             int dia = triangle[i][j] + dp[j+1];
        //             temp[j]=min(down,dia);
        //         }
        //     }
        //     dp=temp;
        // }
        // return dp[0];
        
        // O(1) space by modifying the triangle
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==n-1) triangle[i][j]=triangle[i][j];
                else
                {
                    int dia = triangle[i][j] + triangle[i+1][j+1];
                    int down = triangle[i][j] + triangle[i+1][j];
                    triangle[i][j]=min(down,dia);
                }
            }
        }
        return triangle[0][0];
    }
};