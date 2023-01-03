//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution
{
    private:
        vector<ll> pref_func(string& s)
        {
            ll n = s.size();
            vector<ll> lps(n,0);
            for(ll i=1;i<n;i++)
            {
                ll j = i;
                while(j>0)
                {
                    j = lps[j-1];
                    if(s[i] == s[j])
                    {
                        lps[i] = j+1;
                        break;
                    } 
                    
                }
            }
            return lps;
            // int n = (int)s.length();
            // vector<ll> pi(n);
            // for (int i = 1; i < n; i++) {
            //     int j = pi[i-1];
            //     while (j > 0 && s[i] != s[j])
            //         j = pi[j-1];
            //     if (s[i] == s[j])
            //         j++;
            //     pi[i] = j;
            // }
            // return pi;
        }
    public:
        vector <int> search(string pat, string s)
        {
            string temp = pat + "#" + s;
            vector<ll> lps = pref_func(temp);
            ll n = pat.size();
            vector<int> ans;
            for(ll i=0;i<lps.size();i++)
            {
                if(lps[i] == n)
                {
                    ans.push_back(i-2*n + 1);
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends