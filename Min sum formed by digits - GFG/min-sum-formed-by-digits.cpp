// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        long long res=0;
        long long base=1, carry=0, i;
        for(i=n-2;i>=0;i-=2)
        {
            long long sum = (arr[i] + arr[i+1] + carry);
            carry = sum/10;
            res += (sum%10)*base;
            base*=10;
        }
        if(i==-1)
        {
            long long sum = (arr[i+1] + carry);
            carry = sum/10;
            res += (sum%10)*base;
            base*=10;
        }
        if(carry>0)
        {
            res+=(carry)*base;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends