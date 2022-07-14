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
	            if(isMST[x[0]]==false && keys[x[0]]>x[1])
	            {
	                keys[x[0]]=x[1];
	                parent[x[0]]=curr;
	            }
	        }
	    }
	    return cost;
	}
	int prim_optimized(int n, vector<vector<int>> adj[])
	{
	    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	    vector<int> keys(n,INT_MAX);
	    vector<int> parent(n,-1);
	    vector<bool> isMST(n,false);
	    parent[0]=0;
	    keys[0]=0;
	    int cost=0;
	    pq.push({keys[0],0});
	    for(int i=0;i<n-1;i++)
	    {
	        int curr=pq.top().second;
	        int weight = pq.top().first;
	        pq.pop();
	        isMST[curr]=true;
	        cost+=weight;
	        for(auto&x : adj[curr])
	        {
	            if(isMST[x[0]]==false && keys[x[0]]>x[1])
	            {
	                keys[x[0]]=x[1];
	                pq.push({x[1],x[0]});
	                parent[x[0]]=curr;
	            }
	        }
	    }
	    return accumulate(keys.begin(), keys.end(),0);
	}
	public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        //return prim_brute(n,adj);
        //return prim_optimized(n,adj);
        
        //Prim's Algorithm
        vector<int> key(n, INT_MAX);
        vector<bool> mst(n,false);
        //vector<int> parent(n,-1);
        key[0]=0;
        for(int count=0;count<n-1;count++)
        {
            int mini=INT_MAX,curr;
            for(int i=0;i<n;i++)
            {
                if(mst[i]==false && key[i]<mini)
                {
                    mini=key[i];
                    curr=i;
                }
            }
            mst[curr]=1;
            for(auto &x :adj[curr])
            {
                int node=x[0];
                int weight=x[1];
                if(mst[node]==false && weight<key[node])
                {
                    key[node]=weight;
                    //parent[node]=curr;
                }
            }
        }
        // int ans=0;
        // for(auto &x : key)ans+=x;
        return accumulate(key.begin(),key.end(),0);
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