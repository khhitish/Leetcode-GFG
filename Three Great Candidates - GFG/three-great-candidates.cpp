// { Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int nums[], int n) {
        long long max1,max2,max3;
        max1=max2=max3=INT_MIN;
        long long min1,min2;
        min1=min2=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>max1)
            {
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2)
            {
                max3=max2;
                max2=nums[i];
            }
            else if(nums[i]>max3)
            {
                max3=nums[i];
            }
            
            if(nums[i]<min1)
            {
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2)
            {
                min2=nums[i];
            }
        }
        return max(max1*max2*max3, min1*min2*max1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends