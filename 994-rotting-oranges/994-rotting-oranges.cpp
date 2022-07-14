class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int countfresh=0, countrotten=0;
        queue<pair<int,int>> q;
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    countrotten++;
                }
                else if(grid[i][j]==1)
                {
                    countfresh++;
                }
            }
        }
        if(countrotten==0 && countfresh==0) return 0;
        else if(countrotten!=0 && countfresh==0) return 0;
        else if(countrotten==0 && countfresh!=0) return -1;
        int ans=0;
        vector<int> dir = {0,-1,0,1,0};
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int row = i+dir[k], col=j+dir[k+1];
                    if(row<0 || row>=m || col<0 || col>=n || grid[row][col]!=1) continue;
                    countfresh--;
                    grid[row][col]=2;
                    q.push({row,col});
                }
            }
            ans++;     
        }
        if(countfresh==0) return ans-1;
        else return -1;
    }
};