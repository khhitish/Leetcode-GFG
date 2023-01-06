//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution 
{
    private:
    ll minswaps(vector<int>& v)
    {
        ll n=v.size();
        vector<pair<ll,ll>> vs(n);
        for(ll i=0;i<n;i++)
        {
            vs[i] = {v[i],i};
        }
        sort(vs.begin(), vs.end());
        vector<ll> adj(n);
        for(ll i=0;i<n;i++)
        {
            ll ogi = vs[i].second;
            ll sortedi = i;
            adj[ogi]=sortedi;
        }
        ll c = 0;
        vector<ll> comp(n);
        vector<ll> vis(n);
        for(ll i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                ll curr = i;
                vis[curr] = 1;
                comp[curr] = c;
                while(vis[adj[curr]] == 0)
                {
                    curr = adj[curr];
                    vis[curr] = 1;
                    comp[curr] = c;
                }
                
            }
        }
        // every component will form a cycle and to put the members of the component we need cycle length -1 steps. So for every cycle len-1. Final ans = len1 - 1 + len2 - 1 ..... == n - c
        return n-c;
    }
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    return minswaps(nums);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends