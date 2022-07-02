// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
private:
    string solve (string& s)
    {
        string ans;
        int i=0, n=s.size();
        while(i<n)
        {
            if(i<n && s[i]==s[i+1])
            {
                char temp=s[i];
                while(s[i]==temp)i++;
            }
            else
            {
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
public:
    string rremove(string s){
        int sz = s.size();
        int newsz = INT_MIN;
        while(sz>newsz)
        {
            sz=s.size();
            s=solve(s);
            newsz=s.size();
        }
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends