// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> board){
        for (int i = 0; i < 9; i++)
        {
            vector<int> row(10, 0), col(10, 0), box(10, 0);
            for (int j = 0; j < 9; j++)
            {
                int val;

               	// row
                if (board[i][j] != 0)
                {
                    int val = board[i][j];
                    row[val]++;
                    if (row[val] > 1) return false;
                }

               	// col
                if (board[j][i] !=0)
                {
                    int val = board[j][i];
                    col[val]++;
                    if (col[val] > 1) return false;
                }

               	// box
                int x = 3 *(i / 3) + j / 3, y = 3 *(i % 3) + j % 3;
                if (board[x][y] !=0)
                {
                    val = board[x][y];
                    box[val]++;
                    if (box[val] > 1) return false;
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