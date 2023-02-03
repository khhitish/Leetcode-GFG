//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        int m = matrix.size(), n = matrix[0].size();
        // up=0, right=1, down=2, left=3, updating = add 1 then mod 4
        int dir = 1;
        int row,col;
        int i=0,j=0;
        while(i>=0 && j>=0 && i<m && j<n)
        {
            row=i;col=j;
            if(matrix[i][j] == 1)
            {
                matrix[i][j] = 0;
                dir = (dir+1)%4;
            }
            if(dir == 0)
            {
                i--;
            }
            else if(dir == 1)
            {
                j++;
            }
            else if(dir == 2)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {row,col};
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends