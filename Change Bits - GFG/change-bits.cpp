// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int n) {
        int ans=0;
        int lim = log2(n)+1;
        for(int i=0;i<lim;i++)
        {
            ans += 1<<i;
        }
        vector<int> v;
        v.push_back(ans-n);
        v.push_back(ans);
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends