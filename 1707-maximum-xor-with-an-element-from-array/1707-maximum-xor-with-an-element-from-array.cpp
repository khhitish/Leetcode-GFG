// https://youtu.be/Q8LhG9Pi5KM
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
        vector<int> maximizeXor(vector<int> &nums, vector<vector< int>> &queries)
        {
            Trie *t = new Trie();

            sort(nums.begin(), nums.end());
            vector<vector < int>> offlinequeries;
            for (int i = 0; i < queries.size(); i++)
            {
                offlinequeries.push_back({ queries[i][1],queries[i][0],i });
            }
            sort(offlinequeries.begin(), offlinequeries.end());
            int arrindex = 0;
            vector<int> ansarr(queries.size());
            for (int i = 0; i < offlinequeries.size(); i++)
            {
                int maxi = offlinequeries[i][0];
                int x = offlinequeries[i][1];
                int index = offlinequeries[i][2];

                while (arrindex < nums.size() && nums[arrindex] <= maxi)
                {
                    t->insert(nums[arrindex]);
                    arrindex++;
                }
                if (arrindex == 0)	// nothing smaller or equal to maxi, trie empty return -1
                {
                    ansarr[index] = -1;
                }
                else
                {
                    int ans = t->getmax(x);
                    ansarr[index] = ans;
                }
            }
            return ansarr;
        }
};