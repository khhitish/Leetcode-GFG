// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    void dfs(int i, int d, vector<int>& vis, vector<vector<int>>& adj, int& count)
    {
        if(i==d)
        {
            count++;
            return;
        }
        vis[i]=1;
        for(auto&x : adj[i])
        {
            if(!vis[x])
            {
                dfs(x,d,vis,adj,count);
            }
        }
        vis[i]=0;
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<vector<int>> adj(n);
	    for(auto&x : edges)
	    {
	        adj[x[0]].push_back(x[1]);
	    }
	    vector<int> vis(n,0);
	    int count=0;
	    dfs(s,d,vis,adj,count);
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends