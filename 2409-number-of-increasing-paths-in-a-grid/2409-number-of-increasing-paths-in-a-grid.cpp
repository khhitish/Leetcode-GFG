class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        int m = grid.size(), n = grid[0].size();       
        int ans = 1, mod = 1e9 + 7;
        vector<int> dir = {0,-1,0,1,0};
        for(int k=0;k<4;k++) {
            int row = i + dir[k], col = j + dir[k+1];
            if(row<0 || row>=m || col<0 || col>=n || grid[row][col] >= grid[i][j]) continue;
            ans = (ans + helper(row,col,grid,dp))%mod;
        }
        return dp[i][j] = ans;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        vector<vector<int>> dp(m, vector<int> (n,-1));
        int ans = 0, mod = 1e9+7;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans = (ans + helper(i,j,grid,dp))%mod;
            }
        }
        return ans;
    }
};