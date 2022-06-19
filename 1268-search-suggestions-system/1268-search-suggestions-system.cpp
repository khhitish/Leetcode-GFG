struct Node
{
    Node *links[26];
    bool flag;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
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
        return flag == true;
    }
};

class Trie
{
    private:
        Node * root;
    public:
    Trie()
    {
        root= new Node();
    }
    void insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i])==false)
            {
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    void helper(Node* node, string& sol, vector<string>& ans)
    {
        if(node->isEnd())
        {
            ans.push_back(sol);
        }
        for(int i=0;i<26;i++)
        {
            if(ans.size()==3) return;
            char curr='a' + i;
            if(node->containsKey(curr))
            {
                sol.push_back(curr);
                helper(node->get(curr),sol,ans);
                sol.pop_back();
            }
        }
    }
    void printall(string& prefix, vector<string>& ans)
    {
        Node* node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i])) return;
            node=node->get(prefix[i]);
        }
        string sol=prefix;
        helper(node,sol,ans);
    }
};
class Solution
{
    public:
        vector<vector < string>> suggestedProducts(vector<string> &products, string searchWord) {
            Trie* t = new Trie();
            for(auto&x : products)
            {
                t->insert(x);
            }
            string s;
            vector<vector<string>> ans;
            for(auto&x : searchWord)
            {
                s+=x;
                vector<string> temp;
                t->printall(s,temp);
                ans.push_back(temp);
            }
            return ans;
        }
};


















