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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie *t;
        t = new Trie();
        int n=nums.size();
        vector<vector<int>> offlinequeries;
        for(int i = 0;i<queries.size();i++)
        {
            offlinequeries.push_back({queries[i][1],queries[i][0],i});
        }
        sort(nums.begin(), nums.end());
        sort(offlinequeries.begin(), offlinequeries.end());
        int arrindex=0;
        vector<int> ans(queries.size());
        for(auto&x : offlinequeries)
        {
            int maxi = x[0];
            int num = x[1];
            int ind = x[2];
            while(arrindex<n && nums[arrindex]<=maxi)
            {
                t->insert(nums[arrindex]);
                arrindex++;
            }
            if(arrindex==0)
            {
                ans[ind]=-1;
            }
            else
            {
                ans[ind]= t->getmax(num);
            }
        }
        return ans;
    }
};