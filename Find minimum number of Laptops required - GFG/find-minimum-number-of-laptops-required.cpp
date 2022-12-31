//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        // Code here
        vector<vector<int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 1;
        pq.push(v[0][1]);
        for(auto&x : v)
        {
            // cout<<x[0]<<" "<<x[1]<<endl;
        }
        for(int i=1;i<n;i++)
        {
            if(v[i][0] < pq.top())
            {
                ans++;
                // cout<<v[i][0] << " "<<pq.top()<<endl;
            }
            else pq.pop();
            pq.push(v[i][1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends