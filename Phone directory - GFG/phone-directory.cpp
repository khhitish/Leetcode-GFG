// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
struct Node
{
    Node *links[26];
    bool flag;

    bool containsKey(char ch)
    {
        if (links[ch - 'a'] != nullptr) return true;
        return false;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        if (flag == true) return true;
        return false;
    }
};
class Trie
{
    private:
        Node * root;
    public:
        Trie()
        {
            root = new Node();
        }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]) == false)
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]) == false)
            {
                return false;
            }
            node = node->get(word[i]);
        }
        if (node->isEnd() == false) return false;
        return true;
    }

    bool startsWith(string word)
    {
        Node *node = root; 
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]) == false)
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
    void helper(Node* dummy, string& sol, vector<string>& temp)
    {
        if(dummy->isEnd()==true)
        {
            temp.push_back(sol);
        }
        for(int i=0;i<26;i++)
        {
            char curr='a' + i;
            if(dummy->containsKey(curr)==true)
            {
                sol.push_back(curr);
                helper(dummy->get(curr), sol,temp);
                sol.pop_back();
            }
        }
    }
    void printall(string& s, vector<string>& temp)
    {
        Node* dummy=root;
        for(int i=0;i<s.size();i++)
        {
            if(dummy->containsKey(s[i])==false) return;
            dummy=dummy->get(s[i]);
        }
        string sol = s;
        helper(dummy,sol,temp);
        return;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie * t=new Trie();
        for(int i=0;i<n;i++)
        {
            t->insert(contact[i]);
        }
        string prefix;
        vector<vector<string>> ans;
        for(int i=0;i<s.size();i++)
        {
            vector<string> temp;
            prefix+=s[i];
            t->printall(prefix,temp);
            if(temp.size()==0)temp.push_back("0");
            ans.push_back(temp);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends