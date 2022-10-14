//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        map<int,int> mp;
        for(int i=0;i<n;i++)mp[a[i]]++;
        int sum = 0;
        for(auto&x : mp)
        {
            // cout<<x.first<<" "<<x.second<<endl;
        }
        while(mp.size() > 0)
        {
            auto it =--mp.end();
            // cout<<it->first<<" ";
            sum+=it->first;
            it->second--;
            auto it2 = it;
            if(it2!=mp.begin())
            {
                it2--;
                if(it2->first == it->first - 1)
                {
                    it2->second--;
                    if(it2->second==0)mp.erase(it2);
                }
            }
            if(it->second==0)mp.erase(it);
        }
        return sum;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends