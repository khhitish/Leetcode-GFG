// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n=s.size();
		    int m=(1<<n)-1;
		    vector<string> ans;
		    for(int i=0;i<=m;i++)
		    {
		        string temp;
		        for(int j=0;j<n;j++)
		        {
		            if((i & (1<<j))!=0)
		            {
		                temp+=s[j];
		            }
		        }
		        if(temp.size()>0)ans.push_back(temp);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends