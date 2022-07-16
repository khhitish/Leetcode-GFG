class Solution {
private:
    int helper(int i, int j, int m, int n, int maxmoves, vector<vector<vector<int>>>& dp)
    {
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return 1;
        }
        else if(maxmoves==0) return 0;
        if(dp[i][j][maxmoves]!=-1) return dp[i][j][maxmoves];
        int mod = 1e9+7;
        vector<int> dir={0,-1,0,1,0};
        int ans=0;
        for(int k=0;k<4;k++)
        {
            int row = i + dir[k], col = j + dir[k+1];
            ans= (ans + helper(row,col,m,n,maxmoves-1,dp))%mod;
        }
        return dp[i][j][maxmoves] = ans;
    }
public:
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove+1,-1)));
        return helper(sr,sc,m,n,maxMove,dp);
    }
};