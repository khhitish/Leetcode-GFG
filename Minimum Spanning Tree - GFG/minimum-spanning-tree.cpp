// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class DSU 
{
    private:
    vector<int> par;
    vector<int> rank;
    public:
    DSU(int n)
    {
        par.resize(n,0);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        rank.resize(n,1);
    }
    int find_par(int x)
    {
        if(par[x]==x) return x;
        int temp = find_par(par[x]);
        par[x]=temp;
        return temp;
    }
    void Union(int x, int y)
    {
        int px = find_par(x);
        int py = find_par(y);
        if(px!=py)
        {
            if(rank[px]>rank[py])
            {
                par[py]=px;
            }
            else if(rank[px]<rank[py])
            {
                par[px]=py;
            }
            else
            {
                par[px]=py;
                rank[py]++;
            }
        }
    }
};
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
	int kruskal(int n, vector<vector<int>> adj[])
	{
	    vector<vector<int>> edges;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            edges.push_back({adj[i][j][1],i,adj[i][j][0]});
	        }
	    }
	    sort(edges.begin(), edges.end());
	    DSU d(n);
	    int cost=0;
	    for(auto&x : edges)
	    {
	        int u=x[1], v=x[2], w=x[0];
	        if(d.find_par(u)!=d.find_par(v))
	        {
	            cost+=w;
	            //cout<<d.find_par(u)<<" "<<d.find_par(v)<<endl;
	            d.Union(u,v);
	        }
	    }
	    return cost;
	}
	public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        //return prim_brute(n,adj);
        //return prim_optimized(n,adj);
        return kruskal(n,adj);
        
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