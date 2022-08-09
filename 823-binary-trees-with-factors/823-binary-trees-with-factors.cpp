class Solution {
public:
    // check solution
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mod = 1e9 + 7, n = arr.size();
        vector<long long> dp(n,1);
        unordered_map<int,int> mpp;
        for(int i = 0;i<n;i++)
        {
            mpp[arr[i]] = i;
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0; j<i;j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    int left = j;
                    if(mpp.count(arr[i] / arr[j])!=0)
                    {
                        int right = mpp[arr[i]/arr[j]];
                        dp[i] = (dp[i] + (dp[left]*dp[right])%mod)%mod;
                    }
                }
            }
        }
        int ans = 0;
        for(auto&x : dp)
        {
            ans = (ans + x)%mod;
        }
        return ans;
    }
};