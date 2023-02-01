//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    long long helper(int i, int j,int r[], int g[], int b[],vector<vector<long long>>& dp)
    {
        if(i == -1)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans = LLONG_MAX;
        if(j!=1)
        {
            ans = min(ans, r[i] + helper(i-1,1,r,g,b,dp));
        }
        if(j!=2)
        {
            ans = min(ans, g[i] + helper(i-1,2,r,g,b,dp));
        }
        if(j!=3)
        {
            ans = min(ans, b[i] + helper(i-1,3,r,g,b,dp));
        }
        // cout<<i<<" "<<j<<" "<<ans<<endl;
        return dp[i][j] = ans;
    }
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        vector<vector<long long>> dp(n, vector<long long> (4,-1));
        return helper(n-1,0,r,g,b,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends