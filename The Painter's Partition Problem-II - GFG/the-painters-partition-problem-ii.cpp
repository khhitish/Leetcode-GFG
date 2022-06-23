// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long low = *max_element(arr,arr+n);
        long long high = accumulate(arr,arr+n,0LL);
        long long ans;
        while(low<=high)
        {
            long long mid= low + (high-low)/2;
            // checking if mid time is possible
            long long partitions=1;
            long long tempsum=0;
            for(int i=0;i<n;i++)
            {
                if(tempsum+arr[i]>mid)
                {
                    partitions++;
                    tempsum=0;
                }
                tempsum+=arr[i];
            }
            
            if(partitions>k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
                ans=mid;
            }
        }
        return ans;
        
        //  long long low= *max_element(a, a+n);

        // long long high=0;

        // for(int i=0; i<n; i++)

        // high+=a[i];

        

        // while(low<high)

        // {

        //     long long mid= low+(high-low)/2;

        //     long long painter=1, t=0;

        //     for(int i=0; i<n; i++)

        //     {

        //         t+=a[i];

        //         if(t>mid)

        //         {

        //             t=a[i];

        //             painter++;

        //         }

        //     }

        //     if(painter>k)

        //     low= mid+1;

        //     else

        //     high=mid;

        // }

        // return low;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends