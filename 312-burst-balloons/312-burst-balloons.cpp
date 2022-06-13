class Solution {
private:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=-1e9;
        for(int k=i;k<=j;k++)
        {
            int curr=nums[i-1]*nums[k]*nums[j+1] + helper(i,k-1,nums,dp) + helper(k+1,j,nums,dp);
            ans=max(ans,curr);
        }
        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n=nums.size();
        
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return helper(1,n-2,nums,dp);
    }
};