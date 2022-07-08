class Solution {
private:
    int helper(int i, int p, int n, vector<int>& houses, vector<vector<int>>& cost, int target, vector<vector<vector<int>>> &dp)
    {
        if(i==houses.size())
        {
            if(n==target) return 0;
            else return 1e9;
        }
        if(p!=-1) if(dp[i][p][n]!=-1) return dp[i][p][n];
        int mincost=INT_MAX;
        if(houses[i]!=0)
        {
            if(houses[i]!=p) mincost=helper(i+1,houses[i],n+1,houses,cost,target,dp);
            else mincost=helper(i+1,houses[i],n,houses,cost,target,dp);
        }
        else
        {
            for(int j=0;j<cost[i].size();j++)
            {
                if(j+1!=p) mincost = min(mincost,cost[i][j] + 
                                         helper(i+1,j+1,n+1,houses,cost,target,dp));
                else mincost = min(mincost,cost[i][j] + helper(i+1,j+1,n,houses,cost,target,dp));
            }
        }
        if(p==-1) return mincost;
        return dp[i][p][n]= mincost;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n+1, vector<int>(m+1,-1)));
        int ans = helper(0,-1,0,houses,cost,target,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};