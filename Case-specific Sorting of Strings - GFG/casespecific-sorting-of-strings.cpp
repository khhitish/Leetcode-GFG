//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string u,l;
        for(auto&x : str)
        {
            if(x>='A' && x<='Z')u+=x;
            else l+=x;
        }
        sort(l.begin(), l.end());
        sort(u.begin(), u.end());
        int i=0, j=0;
        for(int k=0;k<n;k++)
        {
            if(str[k]>='A' && str[k]<='Z')
            {
                str[k] = u[i++];
            }
            else str[k]=l[j++];
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends