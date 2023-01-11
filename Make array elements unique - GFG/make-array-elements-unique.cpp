//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        // set<int> st;
        long long prev = 0;
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > prev)
            {
                // st.insert(arr[i]);
                prev = arr[i];
            }
            else
            {
                ans+=prev+1 - arr[i];
                // st.insert(prev+1);
                prev = prev+1;
            }
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends