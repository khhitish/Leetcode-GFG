//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          map<char,int> mpp;
          for(int i=0;i<n;i++)
          {
              mpp[x[i]] = b[i];
          }
          int start=-1,end=-1,tempstart=0;
          int sum=0, ans=INT_MIN;
          for(int i=0;i<w.size();i++)
          {
              int num;
              if(mpp.count(w[i])==0)
              {
                  num = (int)w[i];
              }
              else num = mpp[w[i]];
              sum+=num;
            //   cout<<w[i]<<" "<<num<<" "<<sum<<endl;
              
              
              if(ans < sum)
              {
                  end=i;
                  start=tempstart;
                  ans=sum;
              }
              if(sum<=0)
              {
                  sum=0;
                  tempstart=i+1;
              }
          }
          return w.substr(start,end-start+1);
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends