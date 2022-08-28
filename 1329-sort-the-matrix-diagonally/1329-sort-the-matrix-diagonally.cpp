class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m =mat.size(), n=mat[0].size();
        // int i=m-1, j=0;
        // while(j<n)
        // {
        //     int x = i, y=j;
        //     vector<int> v;
        //     while(x<m && y<n)
        //     {
        //         v.push_back(mat[x][y]);
        //         x++; y++;
        //     }
        //     sort(v.begin(), v.end());
        //     x = i, y=j;
        //     int t = 0;
        //     while(x<m && y<n)
        //     {
        //         mat[x][y] = v[t];
        //         x++;y++;t++;
        //     }
        //     if(i>0) i--;
        //     else j++;
        // }
        // return mat;
        
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mpp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mpp[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j] = mpp[i-j].top();
                mpp[i-j].pop();
            }
        }
        return mat;
    }
};