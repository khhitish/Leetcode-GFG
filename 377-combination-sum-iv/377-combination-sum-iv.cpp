class Solution {
private:
    // int helper(vector<int>& nums, int target, vector<int>& dp)
    // {
    //     if(target == 0) return 1;
    //     int ans = 0;
    //     if(dp[target]!=-1) return dp[target];
    //     for(auto&x : nums)
    //     {
    //         if(target>=x)
    //         ans+=helper(nums,target - x,dp);
    //     }
    //     return dp[target] = ans;
    // }
public:
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target + 1,-1);
        // return helper(nums,target,dp);
        
        vector<long long> dp(target+1,0);
        dp[0]=1;
        for(int i = 1;i<=target;i++)
        {
            int ans = 0;
            for(auto&x : nums)
            {
                if(i >= x)
                {
                    ans+=dp[i - x];
                }
            }
            dp[i] = ans;
        }
        return dp[target];
    }
};