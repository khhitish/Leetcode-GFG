struct Node
{
    vector<Node*> links = vector<Node*>(26);
    bool flag;
    
    bool containsKey(char ch)
    {
        if(links[ch-'a']==nullptr) return false;
        return true;
    }
    
    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }
    
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    
    void setEnd()
    {
        flag=true;
    }
    
    bool isEnd()
    {
        return flag;
    }
};


class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++)
        {
            char c = word[i];
            if(curr->containsKey(c)==false)
            {
                curr->put(c,new Node());
            }
            curr = curr->get(c);
        }
        curr->setEnd();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++)
        {
            char c = word[i];
            if(curr->containsKey(c)==false) return false;
            curr = curr->get(c);
        }
        if(curr->isEnd()) return true;
        return false;
    }
    void helper(string& sol, Node* curr, vector<string>& ans)
    {
        if(curr->isEnd())
        {
            ans.push_back(sol);
        }
        for(char c = 'a'; c<='z'; c++)
        {
            if(ans.size()==3) return;
            if(curr->containsKey(c)==true)
            {
                sol.push_back(c);
                helper(sol,curr->get(c),ans);
                sol.pop_back();
            }
        }
    }
    void getsuggestions(string& s, vector<string>& ans)
    {
        Node* curr = root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->containsKey(s[i])==false) return;
            curr = curr->get(s[i]);
        }  
        string sol=s;
        helper(sol,curr,ans);
    }
    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string sw) {
        Trie* t;
        t = new Trie();
        for(auto&x : products)
        {
            t->insert(x);
        }
        string s;
        vector<vector<string>> ans;
        for(int i = 0;i<sw.size();i++)
        {
            s+=sw[i];
            vector<string> temp;
            t->getsuggestions(s,temp);
            ans.push_back(temp);
        }
        return ans;
    }
};