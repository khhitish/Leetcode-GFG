// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
//   private:
//     bool iscycledfs(int curr, vector<int> adj[], vector<int>& vis,vector<int>& dfsvis)
//     {
//         vis[curr]=1;
//         dfsvis[curr]=1;
//         for(auto&x : adj[curr])
//         {
//             if(!vis[x])
//             {
//                 if(iscycledfs(x,adj,vis,dfsvis)==true) return true;
//             }
//             else if(dfsvis[x]==1)
//             {
//                 return true;
//             }
//         }
//         dfsvis[curr]=0;
//         return false;
//     }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        // vector<int> vis(V,0), dfsvis(V,0);
        // for(int i=0;i<V;i++)
        // {
        //     if(!vis[i])
        //     {
        //         if(iscycledfs(i,adj,vis,dfsvis)) return true;
        //     }
        // }
        // return false;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto&x : adj[i])
            {
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        int cnt=0;
        vector<int> topo;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            topo.push_back(curr);
            cnt++;
            for(auto&x : adj[curr])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        if(cnt!=V) return true;
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends