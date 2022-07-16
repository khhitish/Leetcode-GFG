class Solution {
    // https://youtu.be/nGJmxkUJQGs
private:
    // memoization
    // int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp)
    // {
    //     if(i==prices.size()) return 0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     if(buy==1)
    //     {
    //         dp[i][buy]= max(helper(i+1,buy,prices,dp), helper(i+1,buy-1,prices,dp)-prices[i]);
    //     }
    //     else
    //     {
    //         dp[i][buy]=max(helper(i+1,buy,prices,dp),helper(i+1,buy+1,prices,dp)+prices[i]);
    //     }
    //     return dp[i][buy];
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        // memoization
        // vector<vector<int>> dp(n, vector<int> (2,-1));
        // return helper(0,1,prices,dp);
        
        // tabulation
        // vector<vector<int>> dp(n+1, vector<int> (2,0));
        // dp[n][0]=0; dp[n][1]=0; // cant have any sort of profit or loss at nth day since cant buy or sell
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=1;j>=0;j--)
        //     {
        //         if(j==1)
        //         {
        //             dp[i][j]=max(dp[i+1][j],dp[i+1][j-1] -prices[i]);
        //         }
        //         else
        //         {
        //             dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]+prices[i]);
        //         }
        //     }
        // }
        // return dp[0][1];
        
        
        // // space optimisation
        // vector<int> dp(2,0);
        // dp[0]=0; dp[1]=0; // cant have any sort of profit or loss at nth day since cant buy or sell
        // int next = dp[1]; // maintains dp[i+1][j+1] basically dp[i+1][1];
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=1;j>=0;j--)
        //     {
        //         if(j==1)
        //         {
        //             dp[j]=max(dp[j],dp[0] -prices[i]);
        //         }
        //         else // j==0
        //         {
        //             dp[j]=max(dp[0],next+prices[i]);
        //         }
        //     }
        //     next=dp[1]; // maintain this for single array or without this we can use 2 arrays each of size 2
        // }
        // return dp[1];
        
        // greedy
        // sell on every positve slope
        // https://youtu.be/92wsPDEvj1o
        int i=0,ans=0;
        while(i<n-1)
        {
            while(i+1<n && prices[i]>=prices[i+1])i++; //skipping the negative slope to get to a minima for buying
            int buy = prices[i];
            while(i+1<n && prices[i]<=prices[i+1])i++; // skipping the positive slope to get a maxima for selling 
            int sell = prices[i];
            ans+=(sell-buy);
        }
        return ans;
    }
};