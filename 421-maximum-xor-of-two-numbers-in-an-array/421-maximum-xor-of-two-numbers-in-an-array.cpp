struct Node
{
    vector<Node*> links = vector<Node*> (2);
    
    bool containsKey(int bit)
    {
        if(links[bit]==nullptr) return false;
        return true;
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
    
    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
};

class Trie
{
    private:
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(int num)
    {
        Node* curr = root;
        for(int i = 31;i>=0;i--)
        {
            int bit = ((num>>i) & 1);
            if(curr->containsKey(bit)==false)
            {
                curr->put(bit, new Node());
            }
            curr = curr->get(bit);
        }
    }
    
    int getmax(int x)
    {
        int ans=0;
        Node* curr = root;
        for(int i=31;i>=0;i--)
        {
            int bit = ((x>>i) & 1);
            if(curr->containsKey(bit^1))
            {
                ans|=(1<<i);
                curr = curr->get(bit^1);
            }
            else
            {
                curr = curr->get(bit);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t  =  new Trie();
        for(int i = 0;i<nums.size();i++)
        {
            t->insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            int temp = t->getmax(nums[i]);
            ans = max(ans,temp);
        }
        return ans;
    }
};