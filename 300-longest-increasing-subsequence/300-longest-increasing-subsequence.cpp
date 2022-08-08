class Solution
{
   	// https://youtu.be/IFfYfonAFGc
    private:
       	// memoization
       	// int helper(int i, int prev, vector<int>& nums, vector<vector<int>>& dp)
       	// {
       	//     if(i==nums.size()) return 0;
       	//     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
       	//     int nottake = 0 + helper(i+1,prev,nums,dp);
       	//     int take = 0;
       	//     if(prev==-1 || nums[i]>nums[prev])
       	//     {
       	//         take = 1 + helper(i+1,i,nums,dp);
       	//     }
       	//     return dp[i][prev+1]=max(take,nottake);
       	// }
        public:
        int lengthOfLIS(vector<int> &nums)
        {
            int n = nums.size();

           	// memoization
           	// vector<vector < int>> dp(n, vector<int> (n+1,-1));
           	// return helper(0,-1,nums,dp);

           	// tabulation
           	// vector<vector < int>> dp(n+1, vector<int> (n+1,0));	// n+1 because we need dp[n] and secondly we avoid prev=-1
           	//	// base case already handles since everything is 0
           	// for(int i=n-1;i>=0;i--)
           	// {
           	//     for(int prev=i-1;prev>=-1;prev--)
           	//     {
           	//         int nottake = 0 + dp[i+1][prev+1];
           	//         int take =0;
           	//         if(prev==-1 || nums[i]>nums[prev])
           	//         {
           	//             take = 1 + dp[i+1][i+1];
           	//         }
           	//         dp[i][prev+1]=max(take,nottake);
           	//     }
           	// }
           	// return dp[0][0];

           	// space optimisation single array
           	// vector<int> dp(n+1,0);
           	// for(int i=n-1;i>=0;i--)
           	// {
           	//     for(int prev=i;prev>=0;prev--)
           	//     {
           	//         int nottake = dp[prev];
           	//         int take=0;
           	//         if(prev==0 || nums[prev-1] < nums[i])
           	//         {
           	//             take = 1 + dp[i+1];
           	//         }
           	//         dp[prev]=max(take,nottake);
           	//     }
           	// }
           	// return dp[0];

           	// different type of tabulation, needed to trace back lis
           	// vector<int> dp(n,1);	// dp[i]=length of lis ending at i
           	// int ans=1;
           	// for(int curr=0;curr < n;curr++)
           	// {
           	//     for(int prev=0;prev < curr;prev++)
           	//     {
           	//         if(nums[prev] < nums[curr])
           	//         {
           	//             dp[curr]=max(dp[curr], 1+dp[prev]);
           	//             /*to generate the lis
           	//             if(dp[prev]+1>dp[curr] && dp[prev]+1>dp[curr])	// means curr is a part of the lis 
           	//             {
           	//               parent[curr]=prev;	// later we can trace it back starting from the index where dp[i] has max value basically starting from the index which gives us the length of lis
           	//               dp[curr]=cp[prev]+1;
           	//             }
           	//             */
           	//         }
           	//     }
           	//     ans=max(ans,dp[curr]);
           	// }
           	// return ans;

           	// binary search nlogn time, n space
            vector<int> lis = { nums[0]
            };	// to use .back() without checks i did this, and this is alo fine coz min lis will def be 1
            for (int i = 1; i < n; i++)
            {
                if (lis.back() < nums[i]) lis.push_back(nums[i]);
                else
                {
                    int j = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                    lis[j] = nums[i];
                }
            }
            return lis.size();
        }
};