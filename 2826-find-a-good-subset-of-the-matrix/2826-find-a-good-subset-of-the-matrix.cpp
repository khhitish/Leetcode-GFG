class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> index(32,-1);
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++) {
            int curr = 0;
            for(int j=0;j<n;j++) {
                curr|=(grid[i][j]<<j);
            }
            if(curr == 0) {
                return {i};
            }
            else {
                for(int k=0;k<32;k++) {
                    if((k&curr) == 0 && index[k]!=-1) {
                        return {index[k],i};
                    }
                }
                index[curr] = i;
            }
        }
        return {};
    }
};