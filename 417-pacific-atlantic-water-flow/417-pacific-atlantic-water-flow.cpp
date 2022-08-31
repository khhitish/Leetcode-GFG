class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        int m = grid.size(), n=grid[0].size();
        vis[i][j] = 1;
        vector<int> dir = {0,-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int row = i + dir[k], col = j+dir[k+1];
            if(row<0 || row>=m || col<0 || col>=n || vis[row][col]==1 ||
               grid[row][col]<grid[i][j])continue;
            dfs(row,col,grid,vis);
        }
        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vector<vector<int>> ispac(m, vector<int> (n,0));
        vector<vector<int>> isatl = ispac;
        for(int j=0;j<n;j++)
        {
            dfs(0,j,grid,ispac);
            dfs(m-1,j,grid,isatl);
        }
        for(int i=0;i<m;i++)
        {
            dfs(i,0,grid,ispac);
            dfs(i,n-1,grid,isatl);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ispac[i][j] == 1 && isatl[i][j]==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};