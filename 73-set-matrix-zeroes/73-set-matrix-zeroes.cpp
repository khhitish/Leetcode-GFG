class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto&x : rows)
        {
            for(int j=0;j<n;j++)matrix[x][j]=0;
        }
        for(auto&x : cols)
        {
            for(int i=0;i<m;i++)matrix[i][x]=0;
        }
    }
};