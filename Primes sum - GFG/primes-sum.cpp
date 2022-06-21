// { Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  private:
  bool checkprime(int n)
  {
      //if(n==1) return false;
      for(int i=2;i*i<=n;i++)
      {
          if(n%i==0) return false;
      }
      return true;
  }
  public:
    string isSumOfTwo(int n){
        for(int i=2;i<=n/2;i++)
        {
            if(checkprime(i) && checkprime(n-i)) return "Yes";
        }
        return "No";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}
  // } Driver Code Ends