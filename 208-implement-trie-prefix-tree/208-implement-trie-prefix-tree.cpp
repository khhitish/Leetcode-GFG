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
};

/**
 *Your Trie object will be instantiated and called as such:
 *Trie* obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
 */