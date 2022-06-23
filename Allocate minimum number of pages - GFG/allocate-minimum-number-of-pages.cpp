// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        long long low=INT_MIN,high=0;
        for(int i=0;i<n;i++)
        {
            low=max(low,(long long)arr[i]);
            high+=arr[i];
        }
        while(low<high)
        {
            long long mid = low + (high-low)/2;
            // checking
            long long p=1, sum=0;
            for(int i=0;i<n;i++)
            {
                if(sum + arr[i]>mid)
                {
                    p++;
                    sum=0;
                }
                sum+=arr[i];
                if(p>m) break;
            }
            if(p>m)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends