//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
  int helper(int i, vector<vector<int>>& intervals,vector<int>& dp)
  {
      int n = intervals.size();
      if(i>=n) return 0;
      if(dp[i]!=-1) return dp[i];
      int take=0,nottake=0;
      take = intervals[i][2];
      int j=i+1;
      while(j<n && intervals[j][0]<intervals[i][1])j++;
      take+=helper(j,intervals,dp);
      nottake = helper(i+1,intervals,dp);
      return dp[i] = max(take,nottake);
  }
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n,-1);
        return helper(0,intervals,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends