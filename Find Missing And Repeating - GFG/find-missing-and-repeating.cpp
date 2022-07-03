// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int x=0,y=0,z=0;
        for(int i=1;i<=n;i++)
        {
            x^=i;
            x^=arr[i-1];
        }
        int s=(x & (~(x-1)));
        for(int i=0;i<n;i++)
        {
            if((s&(i+1))!=0)
                y^=(i+1);
            else
                z^=(i+1);
        }
        for(int i=0;i<n;i++)
        {
            if((s&arr[i])!=0)
            y^=arr[i];
            else z^=arr[i];
        }
        bool r=false;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==y){
               r=true;
               
            }
        }
        int *res=new int[2];
        if(r==true){
           res[0]=y;
           res[1]=z;
        }
        else
        {
            res[0]=z;
            res[1]=y;
        }
        return res;
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends