// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
private:
    void helper(int i, int j, vector<int>& path,vector<vector<int>>& ans, vector<vector<int>> &grid)
    {
        int n=grid.size(), m=grid[0].size();
        if(i==n-1 && j==m-1)
        {
            path.push_back(grid[i][j]);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(grid[i][j]);
        if(i+1<n && j<m)
        {
            helper(i+1,j,path,ans,grid);
        }
        if(i<n && j+1<m)
        {
            helper(i,j+1,path,ans,grid);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> path;
        vector<vector<int>> ans;
        
        helper(0,0,path,ans,grid);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends