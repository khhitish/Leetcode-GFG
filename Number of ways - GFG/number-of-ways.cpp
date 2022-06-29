// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int n){
        // at n-1th position, i have 2 choices
        // place the tile horizontalli call count(n-1)
        // or place 4 times verticlly and call count(n-4)
        
        vector<long long> dp(n+1,0);
        dp[1]=1;
        if(n==1) return dp[n];
        dp[2]=1;
        if(n==2) return dp[n];
        dp[3]=1;
        if(n==3) return dp[n];
        dp[4]=2;
        for(int i=5;i<=n;i++)
        {
            dp[i]=dp[i-1] + dp[i-4];
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends