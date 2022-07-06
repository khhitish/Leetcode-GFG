// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    
		    
		  //  queue<char> q;
		  //  vector<int> v(26,0);
		  //  string ans;
		  //  for(int i=0;i<s.size();i++)
		  //  {
		  //      v[s[i]-'a']++;
		  //      q.push(s[i]);
		  //      while(!q.empty() && v[q.front()-'a']>1)q.pop();
		  //      if(q.empty()) ans+='#';
		  //      else ans+=q.front();
		  //  }
		  //  return ans;
		  
		  vector<int> v(26,0);
		  string ans;
		  int track=0;
		  for(int i=0;i<s.size();i++)
		  {
		      v[s[i]-'a']++;
		      if(v[s[track]-'a']>1)
		      {
		          int j;
		          for(j=track;j<=i;j++)
		          {
		              if(v[s[j]-'a']==1)
		              {
		                  track=j;
		                  break;
		              }
		          }
		          if(j==i+1)
		          {
		              ans+='#';
		              track=j;
		          }
		          else
		          {
		              ans+=s[track];
		          }
		      }
		      else
		      {
		          ans+=s[track];
		      }
		  }
		  return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends