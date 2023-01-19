//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        int ans1 = 0, ans2 = 0;
        int a1 = a, b1 = b;
        while(a1>c)
        {
            a1/=2;
            ans1++;
        }
        while(b1>d)
        {
            b1/=2;
            ans1++;
        }
        a1 = a;
        b1 = b;
        while(a1>d)
        {
            a1/=2;
            ans2++;
        }
        while(b1>c)
        {
            b1/=2;
            ans2++;
        }
        return min(ans1,ans2);
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends