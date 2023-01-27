//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int helper(int i, string& s, vector<int>& dp)
        {
            int n = s.size();
            if(i >= n) return 1;
            if(dp[i]!=-1) return dp[i];
            int one=0,two=0;
            if(s[i]>='1' && s[i]<='9')
            one = helper(i+1,s,dp);
            string temp = s.substr(i,2);
            int num = stoi(temp);
            if(num<=26 && num>=10)
            {
                two = helper(i+2,s,dp);
            }
            int mod = 1e9 + 7;
            return dp[i] = (one + two)%mod;
        }
	public:
		int CountWays(string str){
		    int n = str.size();
		    vector<int> dp(n,-1);
		    return helper(0,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends