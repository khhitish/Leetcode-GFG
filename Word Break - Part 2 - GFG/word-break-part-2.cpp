// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
 void helper(int i, int ls, unordered_set<string>& st, string& s, string& temp, vector<string>& ans)
{
    if(i==s.size()-1)
    {
        if(st.count(s.substr(ls,i-ls+1))!=0)
        {
            temp+=s[i];
            ans.push_back(temp);
            temp.pop_back();
        }
        return;
    }
    temp+=s[i];
    //cout<<temp<<endl;
    if(st.count(s.substr(ls,i-ls+1))!=0)
    {
        temp+=' ';
        helper(i+1,i+1,st,s,temp,ans);
        temp.pop_back();
    }
    helper(i+1,ls,st,s,temp,ans);
    temp.pop_back();
}
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> st;
    for(auto&x : dict)
    {
        st.insert(x);
    }
    string temp;
    vector<string> ans;
    helper(0,0,st,s,temp,ans);
    return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends