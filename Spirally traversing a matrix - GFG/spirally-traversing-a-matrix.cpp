// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
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

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends