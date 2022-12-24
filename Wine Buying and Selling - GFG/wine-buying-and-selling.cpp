//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      long long ans = 0;
      int buy = 0, sell = 0;
      while(true)
      {
          while(buy<n && arr[buy]<=0)
          {
              buy++;
          }
          while(sell<n && arr[sell]>=0)
          {
              sell++;
          }
          if(buy == n && sell == n) break;
          int temp = min(arr[buy], -arr[sell]);
          arr[buy]-=temp;
          arr[sell]+=temp;
        //   cout<<buy<<" "<<sell<<" "<<arr[buy]<<" "<<arr[sell]<<endl;
          ans+=(1LL*temp)*(abs(sell-buy));
      }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends