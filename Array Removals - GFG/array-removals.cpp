//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        int l=0, r=0, n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        while(r<n)
        {
            if(arr[r] - arr[l] <=k)
            {
                ans = max(ans,r-l+1);
                r++;
            }
            else l++;
        }
        return n - ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends