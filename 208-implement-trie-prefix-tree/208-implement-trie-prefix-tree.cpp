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
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.size();i++)
        {
            char c = prefix[i];
            if(curr->containsKey(c)==false) return false;
            curr = curr->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */