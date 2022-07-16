// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  private:
    bool helper(int ind, int currsum, int target, int k, int n, int a[], bool used[] )
    {
        if(k==1) return true;
        if(currsum==target)
        {
            return helper(0,0,target,k-1,n,a,used);
        }
        for(int i=ind;i<n;i++)
        {
            if(used[i]==false && a[i]+currsum<=target)
            {
                used[i]=true;
                if(helper(i,currsum+a[i], target,k,n,a,used)) return true;
                used[i]=false;
            }
        }
        return false;
    }
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         if(k==1) return true;
         int sum=0;
         for(int i=0;i<n;i++)sum+=a[i];
         if(sum%k!=0) return false;
         int target = sum/k;
         bool used[n]={false};
         return helper(0,0,target,k,n,a,used);
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends