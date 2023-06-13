class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            int rowstart = grid[i][0];
            for(int j=0;j<n;j++) {
                if(grid[0][j] == rowstart) {
                    bool flag = true;
                    for(int k=0;k<n;k++) {
                        if(grid[i][k] != grid[k][j]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)ans++;
                }
            }
        }
        return ans;
    }
};