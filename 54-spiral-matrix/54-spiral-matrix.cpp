class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rend=matrix.size(), cend=matrix[0].size();
        int rstart=0, cstart=0;
        vector<int> ans;
        while(rstart<rend && cstart<cend)
        {
            for(int i=cstart;i<cend;i++)
            {
                ans.push_back(matrix[rstart][i]);
            }
            rstart++;
            
            for(int i=rstart;i<rend;i++)
            {
                ans.push_back(matrix[i][cend-1]);
            }
            cend--;
            
            if(rstart<rend)
            {
                for(int i=cend-1;i>=cstart;i--)
                {
                    ans.push_back(matrix[rend-1][i]);
                }
                rend--;
            }
            
            if(cstart<cend)
            {
                for(int i=rend-1;i>=rstart;i--)
                {
                    ans.push_back(matrix[i][cstart]);
                }
                cstart++;       
            }

        }
        return ans;        
    }
};