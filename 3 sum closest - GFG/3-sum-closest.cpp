// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int nums[], int n, int target)
    {
        sort(nums,nums+n);
        int ans =20000;
        int i=0;
        while(i<n-2)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                //cout<<sum<<endl;
                if (abs(target - sum) < abs(target - ans))
                {
                    ans = sum;
                }
                if (sum > target) k--;
                else if (sum < target) j++;
                else return ans;
            }
            int t = nums[i];
            while (i < n - 2 && nums[i] == t) i++; // skipping the duplicates
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Ends