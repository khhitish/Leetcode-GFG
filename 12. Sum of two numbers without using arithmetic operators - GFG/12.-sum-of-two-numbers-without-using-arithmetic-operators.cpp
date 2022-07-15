// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
        int ans=0, carry=0,pos=0;
        while(a!=0 || b!=0 || carry!=0)
        {
            int x = (a&1), y = (b&1);
            int count1=0;
            if(x==1)count1++;
            if(y==1)count1++;
            if(carry==1)count1++;
            carry = count1/2;
            if(count1%2==1)
            {
                ans=(ans ^ (1<<pos));
            }
            pos++;
            a=(a>>1);
            b=(b>>1);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends