// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        reverse(s.begin(), s.end());
        int start=0, end;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.')
            {
                end=i;
                reverse(s.begin()+start, s.begin()+ end);
                start=i+1;
            }
        }
        
        reverse(s.begin()+start, s.end());
        return s;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends