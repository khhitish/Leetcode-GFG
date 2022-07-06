// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        stack<int> s;
        vector<int> ans(n,INT_MIN);
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n || arr[s.top()]>=arr[i]))//i==n added to avoid writing another while loop
            {
                int temp=s.top();
                s.pop();
                int maxlen;
                if(s.empty())
                {
                    maxlen = i-(-1)-2;
                }
                else
                {
                    maxlen = i-s.top()-2;
                }
                ans[maxlen]=max(ans[maxlen],arr[temp]);
            }
            s.push(i);
        }
        for(int i=n-2;i>=0;i--)
        {
            ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends