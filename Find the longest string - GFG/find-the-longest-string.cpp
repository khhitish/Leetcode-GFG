//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
private:
    static bool comp(string& s1, string& s2)
    {
        if(s1.size() < s2.size()) return true;
        else if(s1.size() > s2.size()) return false;
        else
        {
            return s1<s2;
        }
    }
public:
    string longestString(vector<string> &words)
    {
        sort(words.begin(), words.end(),comp);
        // for(auto&)
        int n = words.size();
        unordered_set<string> st;
        string ans;
        for(int i=0;i<n;i++)
        {
            string temp;
            bool flag = true;
            st.insert(words[i]);
            for(auto&x : words[i])
            {
                temp+=x;
                if(st.count(temp) == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                if(words[i].size() > ans.size()) ans = words[i];
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
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends