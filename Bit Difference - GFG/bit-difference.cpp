// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int n, long long int arr[])
    {
        long long ans=0, mod=1e9+7;
        for(int i=0;i<32;i++)
        {
            long long ones=0;
            for(int j=0;j<n;j++)
            {
                if(((arr[j]>>i)&1)==1)ones++;
            }
            ans= (ans + (ones*(n-ones))%mod)%mod;
        }
        return (ans*2)%mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends