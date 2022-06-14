struct Node
{
    Node *links[2];
    bool containsKey(int bit)
    {
        if (links[bit] != nullptr) return true;
        else return false;
    }

    Node* get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
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

    void insert(int num)
    {
        Node *dummy = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) &(1);
            if (dummy->containsKey(bit) == false)
            {
                dummy->put(bit, new Node());
            }
            dummy = dummy->get(bit);
        }
    }

    int getmax(int x)
    {
        Node *dummy = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) &1;
            if (dummy->containsKey(bit ^ 1) == true)
            {
                ans = ans | (1 << i);
                dummy = dummy->get(bit ^ 1);
            }
            else
            {
                dummy = dummy->get(bit);
            }
        }
        return ans;
    }
};
class Solution
{
    public:
        int findMaximumXOR(vector<int> &nums)
        {
            Trie *t = new Trie();
            for (int i = 0; i < nums.size(); i++)
            {
                t->insert(nums[i]);
            }
            int ans = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                int curr = nums[i];
                ans = max(ans, t->getmax(curr));
            }
            return ans;
        }
};