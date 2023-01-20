//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {
      vector<int> hash(n);
      for(int i=0;i<n;i++)
      {
          if(edge[i]!=-1)hash[edge[i]]+=i;
          
      }
      int ans, maxi = 0;
      for(int i=0;i<n;i++)
      {
          if(hash[i]>=maxi)
          {
              maxi = hash[i];
              ans = i;
          }
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends