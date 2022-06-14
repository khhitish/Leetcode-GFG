struct Node
{
    Node *links[26];
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

    bool isEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag = true;
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
    void insert(string & word)
    {
        Node *dummy = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (dummy->containsKey(word[i]) == false)
            {
                dummy->put(word[i], new Node());
            }
            dummy=dummy->get(word[i]);
        }
        dummy->setEnd();
    }
    bool helper(Node *dummy, string &word, int i)
    {
        if (i == word.size())
        {
            if (dummy->isEnd() == true) return true;
            else return false;
        }
        if (word[i] == '.')
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (dummy->containsKey(ch) == true)
                {
                    if (helper(dummy->get(ch), word, i + 1) == true) return true;
                }
            }
            return false;
        }
        else if (dummy->containsKey(word[i]) == true)
        {
            return helper(dummy->get(word[i]), word, i + 1);
        }
        else return false;
    }
    bool search(string word)
    {
        Node *dummy = root;
        return helper(dummy, word, 0);
        // for(int i=0;i<word.size();i++)
        // {
        //     if(dummy->containsKey(word[i])==true)
        //     {
        //         dummy=dummy->get(word[i]);
        //     }
        //     else return false;
        // }
        // if(dummy->isEnd()) return true;
        // return false;
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