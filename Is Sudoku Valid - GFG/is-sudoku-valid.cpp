// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> board){
        for(int row=0;row<9;row++)
        {
            vector<int> v(10,0);
            for(auto& x: board[row])
            {
                if(x!=0)
                {
                    v[x]++;
                    if(v[x]>1) return false;
                }    
            }
        }
        //validating columns
        for(int col=0;col<9;col++)
        {
            vector<int> v(10,0);
            for(int row=0;row<9;row++)
            {
                if(board[row][col]!=0)
                {
                    v[board[row][col]]++;
                    if(v[board[row][col]]>1) return false;
                }
            }
        }
        //validating 3*3 squares
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                vector<int> v(10,0);
                for(int i=y*3; i<y*3+3;i++)
                {
                    for(int j=x*3;j<x*3 +3;j++)
                    {
                        if(board[i][j]!=0)
                        {
                            v[board[i][j]]++;
                            if(v[board[i][j]]>1) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends