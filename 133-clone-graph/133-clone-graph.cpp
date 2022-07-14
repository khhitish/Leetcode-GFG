/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* og, Node* copy, vector<Node*>& vis)
    {
        for(auto&x : og->neighbors)
        {
            if(vis[x->val]==nullptr)
            {
                vis[x->val]= new Node(x->val);
                copy->neighbors.push_back(vis[x->val]);
                dfs(x,vis[x->val],vis);
            }
            else
            {
                copy->neighbors.push_back(vis[x->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        vector<Node*> vis(101,nullptr);
        vis[node->val] = new Node(node->val);
        dfs(node,vis[node->val],vis);
        return vis[node->val];
    }
};