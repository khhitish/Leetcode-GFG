//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int k, vector<int> &arr) {
        // code here
        vector<int> pref(n);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            pref[i] = sum;
        }
        vector<int> factors;
        for(int i=1;i*i<=sum;i++)
        {
            if(sum%i == 0)
            {
                factors.push_back(i);
                if(i!=sum/i)
                {
                    factors.push_back(sum/i);
                }
            }
        }
        int ans = 1;
        for(int i=0;i<factors.size();i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(pref[j]%factors[i] == 0)
                {
                    cnt++;
                }
            }
            if(cnt>=k)
            {
                ans = max(ans,factors[i]);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends