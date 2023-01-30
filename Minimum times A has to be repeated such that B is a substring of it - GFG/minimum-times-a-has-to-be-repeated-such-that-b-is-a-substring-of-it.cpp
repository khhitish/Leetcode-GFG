//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        string t;
        int cnt = 0;
        while(t.size() < b.size())
        {
            t+=a;
            cnt++;
        }
        if(t.find(b)!=string::npos) return cnt;
        t+=a;
        cnt++;
        if(t.find(b)!=string::npos) return cnt;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends