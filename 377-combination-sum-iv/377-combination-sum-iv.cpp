class Solution {
private:
    int helper(vector<int>& nums, int target, vector<int>& dp)
    {
        if(target == 0) return 1;
        if(target<0) return 0;
        int ans = 0;
        if(dp[target]!=-1) return dp[target];
        for(auto&x : nums)
        {
            ans+=helper(nums,target - x,dp);
        }
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1,-1);
        return helper(nums,target,dp);
    }
};