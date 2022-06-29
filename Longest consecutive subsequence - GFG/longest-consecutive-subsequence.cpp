// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      unordered_set<int> s;
      for(int i=0;i<n;i++)
      {
          s.insert(arr[i]);
      }
      int ans=1;
      for(int i=0;i<n;i++)
      {
          int x = arr[i];
          if(s.count(x)==0) continue;
          s.erase(x);
          int tempans=1,prev=x-1, next=x+1;
          while(s.count(prev)>0)
          {
              s.erase(prev);
              tempans++;
              prev--;
          }
          while(s.count(next)>0)
          {
              s.erase(next);
              tempans++;
              next++;
          }
          ans=max(ans,tempans);
      }
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends