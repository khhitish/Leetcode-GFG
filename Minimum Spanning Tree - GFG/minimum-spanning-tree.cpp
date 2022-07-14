// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	private:
	int prim_brute(int n, vector<vector<int>> adj[])
	{
	    vector<int> keys(n,INT_MAX);
	    vector<bool> isMST(n,false);
	    vector<int> parent(n,-1);
	    keys[0]=0;
	    parent[0]=0;
	    int cost=0;
	    for(int i=0;i<n;i++)
	    {
	        int curr;
	        int mini=INT_MAX;
	        for(int j=0;j<n;j++)
	        {
	            if(isMST[j]==false && keys[j]<mini)
	            {
	                mini=keys[j];
	                curr=j;
	            }
	        }
	        cost+=keys[curr];
	        isMST[curr]=true;
	        for(auto&x : adj[curr])
	        {
	            if(keys[x[0]]>x[1])
	            {
	                keys[x[0]]=x[1];
	                parent[x[0]]=curr;
	            }
	        }
	    }
	    return cost;
	}
	public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        return prim_brute(n,adj);
    }
};
// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends