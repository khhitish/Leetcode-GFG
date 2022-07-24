struct Node
{
    vector<Node*> links = vector<Node*> (26);
    bool flag;

    bool containsKey(char ch)
    {
        if (links[ch - 'a'] == nullptr) return false;
        return true;
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
        return flag;
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
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if (curr->containsKey(c) == false)
            {
                curr->put(c, new Node());
            }
            curr = curr->get(c);
        }
        curr->setEnd();
    }
    bool helper(int i, string &word, Node *curr)
    {
        if (i == word.size())
        {
            if (curr->isEnd()) return true;
            return false;
        }
        if (word[i] == '.')
        {
            for (char ch = 'a'; ch <='z' ; ch++)
            {
                if (curr->containsKey(ch) == true)
                {
                    if (helper(i + 1, word, curr->get(ch)) == true) return true;
                }
            }
        }
        else
        {
            if (curr->containsKey(word[i]) == true)
            {
                return helper(i + 1, word, curr->get(word[i]));
            }
        }
        return false;
    }
    bool search(string word)
    {
        Node* curr = root;
       // return helper(curr,word,0);
        return helper(0,word,curr);
    }
};
class WordDictionary
{
    private:
        Trie * t;
    public:
        WordDictionary()
        {
            t = new Trie();
        }

    void addWord(string word)
    {
        t->insert(word);
    }

    bool search(string word)
    {
        return t->search(word);
    }
};

/**
 *Your WordDictionary object will be instantiated and called as such:
 *WordDictionary* obj = new WordDictionary();
 *obj->addWord(word);
 *bool param_2 = obj->search(word);
 */