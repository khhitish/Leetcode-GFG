// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
    {
        priority_queue<long long> pq;
        for(int i=0;i<n;i++)
        {
            auto x =a[i];
            pq.push(x);
            if(pq.size()>=k2) pq.pop();
        }
        long long ans=0;
        while(pq.size()>k1)
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends