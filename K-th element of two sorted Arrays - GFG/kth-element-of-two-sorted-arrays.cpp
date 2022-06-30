// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low=1, high=INT_MAX;
        int ans, reqcount=k-1;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            int count=0, exists=0;
            int index1= (lower_bound(arr1,arr1+n,mid) - arr1);
            int index2=(lower_bound(arr2,arr2+m,mid) - arr2);
            if( (index1<n && arr1[index1]==mid) || (index2<m && arr2[index2]==mid)) exists=1;
            count=index1+index2;
            if(count>reqcount) high=mid-1;
            else if(count<reqcount)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                if(exists==1) return mid;
                else low=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends