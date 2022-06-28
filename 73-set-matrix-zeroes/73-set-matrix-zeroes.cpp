// https://youtu.be/3ylBTHCiihw
class Solution
{
    public:
        void setZeroes(vector<vector < int>> &matrix)
        {
            int m = matrix.size(), n = matrix[0].size();

           	// m + n extra space
           	// unordered_set<int> rows, cols;
           	// for(int i=0;i < m;i++)
           	// {
           	//     for(int j=0;j < n;j++)
           	//     {
           	//         if(matrix[i][j]==0)
           	//         {
           	//             rows.insert(i);
           	//             cols.insert(j);
           	//         }
           	//     }
           	// }
           	// for(auto&x : rows)
           	// {
           	//     for(int j=0;j < n;j++)matrix[x][j]=0;
           	// }
           	// for(auto&x : cols)
           	// {
           	//     for(int i=0;i < m;i++)matrix[i][x]=0;
           	// }
            
            bool firstrow=false, firstcol=false; // maintaining this separately because if matrix[0][0]=0 then we dont know if we just want col 0 to be 0 or row 0 to be 0 or both to be 0 since the marking position is overlapping
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        if(i==0)firstrow=true;
                        if(j==0)firstcol=true;
                        
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for(int i=1;i<m;i++)
            {
                if(matrix[i][0]==0)
                {
                    for(int j=0;j<n;j++) matrix[i][j]=0;
                }
                if(firstcol==true)
                {
                    matrix[i][0]=0;
                }
            }
            for(int j=1;j<n;j++)
            {
                if(matrix[0][j]==0)
                {
                    for(int i=0;i<m;i++) matrix[i][j]=0;
                }
                if(firstrow==true)
                {
                    matrix[0][j]=0;
                }
            }
        }
};