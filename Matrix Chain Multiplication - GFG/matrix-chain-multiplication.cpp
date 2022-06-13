// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    // memoization
    int helper(int i, int j, int arr[], vector<vector<int>>& dp)
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int curr = arr[i-1]*arr[k]*arr[j] + helper(i,k,arr,dp) + helper(k+1,j,arr,dp);
            ans=min(ans,curr);
        }
        return dp[i][j]=ans;
    }
public:
    int matrixMultiplication(int n, int arr[])
    {
        // memoization
        // vector<vector<int>> dp(n, vector<int> (n,-1));
        // return helper(1,n-1,arr,dp);
        
        // tabulation
        vector<vector<int>> dp(n, vector<int> (n,0));
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i;j<=n-1;j++)
            {
                if(i==j)dp[i][j]=0;
                else
                {
                    int ans=1e9;
                    for(int k=i;k<j;k++)
                    {
                        ans=min(ans, arr[i-1]* arr[k] * arr[j] + dp[i][k] + dp[k+1][j]);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[1][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends