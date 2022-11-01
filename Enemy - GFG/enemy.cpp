//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            vector<int> row,col;
            row.push_back(0);
            col.push_back(0);
            row.push_back(n+1);
            col.push_back(m+1);
            for(auto&x : enemy)
            {
                row.push_back(x[0]);
                col.push_back(x[1]);
            }
            sort(col.begin(), col.end());
            int max_col = 0;
            for(int i=0;i<col.size()-1;i++)
            {
                max_col = max(max_col,col[i+1] - col[i] - 1);
            }
            sort(row.begin(), row.end());
            int max_row = 0;
            for(int i=0;i<row.size()-1;i++)
            {
                max_row = max(max_row, row[i+1] - row[i] - 1);
            }
            // cout<<max_row<<" "<<max_col<<endl;
            return max_row * max_col;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends