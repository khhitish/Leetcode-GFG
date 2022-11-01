//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{ 
private:
 int count(int mid, vector<vector<int>>& matrix){
     int cnt = 0;
     for(int i=0;i<matrix.size();i++)
     {
         int j = upper_bound(matrix[i].begin(), matrix[i].end(),mid) - matrix[i].begin();
         cnt+=j;
     }
     return cnt;
 }
public:
    int median(vector<vector<int>> &matrix, int m, int n){
        // code here  
        int low = 1, high = 2000;
        int ans = -1;
        int num = (m*n)/2 + 1; 
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int temp = count(mid,matrix);
            if(temp >= num)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends