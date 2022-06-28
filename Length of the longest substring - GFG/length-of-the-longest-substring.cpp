// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        int right=0,left=0;
        vector<int> hash(256,-1);
        int n=s.size();
        int ans=0;
        while(right<n)
        {
            char curr = s[right];
            if(hash[curr]!=-1)
            {
                left=max(left,hash[curr] + 1);
            }
            hash[curr]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends