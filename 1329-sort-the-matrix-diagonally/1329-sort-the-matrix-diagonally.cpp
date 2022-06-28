class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m =mat.size(), n=mat[0].size();
        int i=m-1, j=0;
        while(j<n)
        {
            int x = i, y=j;
            vector<int> v;
            while(x<m && y<n)
            {
                v.push_back(mat[x][y]);
                x++; y++;
            }
            sort(v.begin(), v.end());
            x = i, y=j;
            int t = 0;
            while(x<m && y<n)
            {
                mat[x][y] = v[t];
                x++;y++;t++;
            }
            if(i>0) i--;
            else j++;
        }
        return mat;
    }
};