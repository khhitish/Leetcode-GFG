//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    long long modpow(long long base, long long power, long long mod)
    {
        long long ans = 1;
        while(power > 0)
        {
            if(power&1)
            {
                ans = (ans*base)%mod;
                power--;
            }
            else
            {
                base = (base*base)%mod;
                power/=2;
            }
        }
        return ans;
    }
	public:
	int compute_value(int n)
	{
	    vector<long long> fact(n+1);
	    long long mod = 1e9 + 7;
	    fact[0]=1;
	    for(long long i=1;i<=n;i++)
	    {
	        fact[i] = (i*fact[i-1])%mod;
	    }
	    long long ans = 0;
	    for(long long i=0;i<=n;i++)
	    {
	        long long temp = ((fact[n] * modpow(fact[i],mod-2,mod))%mod * modpow(fact[n-i],mod-2,mod))%mod;
	        temp = modpow(temp,2,mod);
	        ans = (ans + temp)%mod;
	    }
	    return (int)ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends