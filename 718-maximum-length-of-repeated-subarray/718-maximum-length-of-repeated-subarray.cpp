class Solution {
    // https://youtu.be/_wP9mWNPL5w
    // https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/413054/ALL-4-ways-Recursion-greater-Top-down-greaterBottom-Up-including-VIDEO-TUTORIAL
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // tabulation easier 2d version 
        int m=nums1.size(), n=nums2.size();
        
        // 2d array
        //vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        // no need to set base case as 0 as everything is already 0
        // for(int i=0;i<=m;i++)
        // {
        //     dp[i][0]=0; //j==0 return 0
        // }
        // for(int j=0;j<=n;j++)
        // {
        //     dp[0][j]=0; //i==0 return 0
        // }
        
        // int ans=0;
        // for(int i=1;i<=m;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         if(nums1[i-1]==nums2[j-1])
        //         {
        //             dp[i][j]=1 + dp[i-1][j-1];
        //         }
        //         else
        //         {
        //             dp[i][j] = 0;
        //         }
        //         ans=max(ans,dp[i][j]);
        //     }
        // }
        // return ans;
        
        // 1d array
        vector<int> dp(n+1,0);
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=n;j>=1;j--) // since we need left value of prev row, we can use single array only if we traverse inner loop in reverse then we will have the prev value unharmed
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[j]=1 + dp[j-1];
                }
                else
                {
                    dp[j] = 0;
                }
                ans=max(ans,dp[j]);
            }
        }
        return ans;
    }
};