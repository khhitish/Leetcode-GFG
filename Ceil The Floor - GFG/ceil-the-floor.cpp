// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}
// } Driver Code Ends


pair<int, int> getFloorAndCeil(int v[], int n, int x) {
    int low=0, high=n-1;
    int c=-1,f=-1;
    sort(v,v+n);
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(v[mid]==x) return {x,x};
        else if(v[mid]>x)
        {
            c=v[mid];
            high=mid-1;
        }
        else
        {
            f=v[mid];
            low=mid+1;
        }
    }
    return {f,c};
}