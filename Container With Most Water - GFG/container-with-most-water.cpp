//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long arr[], int len)
{
    int low = 0, high = len-1;
    long long ans = 0;
    while(low<high)
    {
        ans = max(ans, min(arr[low],arr[high])*(high - low));
        if(arr[low] < arr[high])low++;
        else if(arr[low] > arr[high])high--;
        else
        {
            if(arr[low+1] > arr[high -1])low++;
            else high--;
        }
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends