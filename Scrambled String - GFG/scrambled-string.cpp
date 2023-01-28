//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
private:
    bool helper(string& s1, string& s2, unordered_map<string,bool>& mp)
    {
        int n = s1.size();  // same as s2.size()
        string hash = s1 + "#" + s2;
        if(s1 == s2) return true;
        else if(n == 1) return false;  // size = 1 and unequal characters
        else if(mp.count(hash)!=0) return mp[hash];
        else
        {
            for(int i=0;i<n-1;i++)
            {
                int l1 = i+1, l2 = n-i-1;
                string s11 = s1.substr(0,l1);
                string s12 = s1.substr(l1);

                string s21 = s2.substr(0,l1);
                string s22 = s2.substr(l1);
                if(helper(s11,s21,mp) && helper(s12,s22,mp)) return mp[hash] = true;

                s21 = s2.substr(0,l2);
                s22 = s2.substr(l2);
                if(helper(s11,s22,mp) && helper(s12,s21,mp)) return mp[hash] = true;
            }
        }
        return mp[hash] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        unordered_map<string,bool> mp;
        return helper(s1,s2,mp);
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends