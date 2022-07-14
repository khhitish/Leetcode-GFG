// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  private:
  void dfs(int curr,int par,int& timer, vector<int>& disc, vector<int>& low,
  vector<int>& vis, vector<bool>& ans, vector<int> adj[])
  {
      vis[curr]=1;
      disc[curr]=low[curr]=timer++;
      int countcalls=0;
      for(auto&x : adj[curr])
      {
          if(x==par) continue;
          if(!vis[x])
          {
              dfs(x,curr,timer,disc,low,vis,ans,adj);
              low[curr]=min(low[curr],low[x]);
              if(low[x]>=disc[curr] && par!=-1)
              {
                  ans[curr]=true;
              }
              countcalls++;
          }
          else
          {
              low[curr]=min(low[curr],disc[x]);
          }
      }
      if(countcalls>1 && par==-1)
      {
          ans[curr]=true;
      }
  }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        vector<bool> ans(n,false);
        int timer=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,timer,disc,low,vis,ans,adj);
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==true)res.push_back(i);
        }
        if(res.size()==0) return {-1};
        return res;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends