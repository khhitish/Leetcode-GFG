//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int m = grid.size(), n = grid[0].size();
        int si = source.first, sj = source.second;
        int di = destination.first, dj = destination.second;
        if(grid[si][sj] == 0 || grid[di][dj] == 0) return -1;
        queue<pair<int,int>> q;
        q.push({si,sj});
        grid[si][sj]=0;
        vector<int> dir = {0,-1,0,1,0};
        int level=0;
        while(!q.empty())
        {
            int t = q.size();
            while(t--)
            {
                auto p = q.front();
                q.pop();
                int i = p.first, j= p.second;
                // cout<<i<<" "<<j<<endl;
                if(i == di && j == dj) return level;
                for(int k=0;k<4;k++)
                {
                    int row = i + dir[k], col = j + dir[k+1];
                    // cout<<row<<" "<<col<<endl;
                    // cout<<m<<" "<<n<<endl; 
                    if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==0)continue;
                    grid[row][col] = 0;
                    // cout<<row<<" "<<col<<endl;
                    q.push({row,col});
                }
            }
            level++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends