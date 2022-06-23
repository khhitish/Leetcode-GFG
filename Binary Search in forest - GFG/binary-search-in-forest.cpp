// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        int low=0, high = *max_element(tree,tree+n);
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int curr=0;
            for(int i=0;i<n;i++)
            {
                if(tree[i]>mid) curr+=tree[i]-mid;
            }
            if(curr==k) return mid;
            else if(curr>k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends