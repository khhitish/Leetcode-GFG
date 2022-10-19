//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    bool dfs(int i, vector<int>& vis, int count, vector<vector<int>>& adj)
    {
        vis[i] = 1;
        if(count==vis.size()-1) return true;
         for(auto&x : adj[i])
         {
             if(!vis[x])
             {
                 if(dfs(x,vis,count+1,adj)==true) return true;
             }
         }
         vis[i]=0;
         return false;
    }
    public:
    bool check(int n,int m,vector<vector<int>> edges)
    {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0);
        for(int i = 1;i<=n;i++)
        {
            if(dfs(i,vis,1,adj)) return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends