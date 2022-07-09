class Solution {
private:
    int helper(int i,int k, vector<int>& nums, vector<int>& dp)
    {
        if(i==0)
        {
            return nums[0];
        }
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        for(int j=i-1;j>=max(0,i-k);j--)
        {
            ans=max(ans,nums[i] + helper(j,k,nums,dp));
        }
        return dp[i]=ans;
    }
        
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<int> dp(n,-1);
        // return helper(n-1,k,nums,dp);
        
        vector<int> dp(n);
        priority_queue<pair<int,int>> pq;
        dp[0]=nums[0];
        pq.push({dp[0],0});
        for(int i=1;i<n;i++)
        {
            while(!pq.empty() && pq.top().second<i-k)pq.pop();
            dp[i] = nums[i] + pq.top().first;
            pq.push({dp[i],i});
        }
        return dp[n-1];
    }
};