class Solution {
    // https://youtu.be/IV1dHbk5CDc
    
    // 3d dp approach: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
    // set cap to k
    
    
    
    // 2d dp approach
private:
    //  // memoization
    // int helper(int i, int t, int k, vector<int>& prices, vector<vector<int>>& dp)
    // {
    //     if(i==prices.size() || t==2*k) return 0;
    //     if(dp[i][t]!=-1) return dp[i][t];
    //     if(t%2==0) // even means can only buy
    //     {
    //         dp[i][t]=max(helper(i+1,t+1,k,prices,dp) - prices[i], helper(i+1,t,k,prices,dp));
    //     }
    //     else // can only sell
    //     {
    //         dp[i][t]=max( helper(i+1,t+1,k,prices,dp) + prices[i], helper(i+1, t,k,prices,dp));
    //     }
    //     return dp[i][t];
    // }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        // // memoization
        // vector<vector<int>> dp(n, vector<int> (2*k+1,-1));
        // return helper(0,0,k,prices,dp);
        
        // tabulation
        // vector<vector<int>> dp(n+1, vector<int> (2*k+1,0));
        // // base cases already taken into consideration since vector is initialized to 0
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=2*k-1;j>=0;j--)
        //     {
        //         if(j%2==0) // buy
        //         {
        //             dp[i][j] = max(-prices[i] + dp[i+1][j+1], dp[i+1][j]);
        //         }
        //         else // sell
        //         {
        //             dp[i][j]= max(prices[i] + dp[i+1][j+1], dp[i+1][j]);
        //         }
        //     }
        // }
        // return dp[0][0];
        
        // space optimisation space = k, time=n*k
        // 2 arrays can be done easily, this is single array
        vector<int> dp(2*k+1,0); // this is the last row i==n hence all 0s base case 1
        int ahead=0; // keeps a track of dp[i+1][j+1], will get updated to 0 after every row since for a new row i+1,j+1 is basically j==2*k means dp=0 (base case 2)
        for(int i=n-1;i>=0;i--)
        {
            for(int j=2*k-1;j>=0;j--)
            {
                int temp=dp[j];
                if(j%2==0) // buy
                {
                    dp[j] = max(-prices[i] + ahead, dp[j]);
                }
                else // sell
                {
                    dp[j]= max(prices[i] + ahead, dp[j]);
                }
                ahead=temp;
            }
            ahead=0;
        }
        return dp[0];
        
        
    }
};