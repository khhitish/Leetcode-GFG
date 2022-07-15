class Solution {
private:
    void dfs(int i, int j, int& area, vector<vector<int>>& grid)
    {
        int m=grid.size(), n=grid[0].size();
        if(i<0 || i>=m || j<0 | j>=n || grid[i][j]==0) return;
        grid[i][j]=0;
        area++;
        vector<int> dir = {0,-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int row = i + dir[k], col = j + dir[k+1];
            dfs(row,col,area,grid);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int maxarea=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int area=0;
                    dfs(i,j,area,grid);
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};