class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt=1;
        vector<vector<int>> matrix(n, vector<int> (n,0));
        
        int rend=matrix.size(), cend=matrix[0].size();
        int rstart=0, cstart=0;
        vector<int> ans;
        while(rstart<rend && cstart<cend)
        {
            for(int i=cstart;i<cend;i++)
            {
                matrix[rstart][i] = cnt;
                cnt++;
            }
            rstart++;
            
            for(int i=rstart;i<rend;i++)
            {
                matrix[i][cend-1]=cnt;
                cnt++;
            }
            cend--;
            
            if(rstart<rend)
            {
                for(int i=cend-1;i>=cstart;i--)
                {
                    matrix[rend-1][i]=cnt;
                    cnt++;
                }
                rend--;
            }
            
            if(cstart<cend)
            {
                for(int i=rend-1;i>=rstart;i--)
                {
                    matrix[i][cstart]=cnt;
                    cnt++;
                }
                cstart++;       
            }

        }
        return matrix;      
    }
};