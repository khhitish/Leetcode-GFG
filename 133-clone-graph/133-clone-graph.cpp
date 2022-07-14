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
        
        // // using dfs
        // dfs(node,vis[node->val],vis);
        // return vis[node->val];
        
        // using bfs
        queue<pair<Node*,Node*>> q;
        q.push({node,vis[node->val]});
        while(!q.empty())
        {
            Node* og = q.front().first;
            Node* copy = q.front().second;
            q.pop();
            for(auto &x : og->neighbors)
            {
                if(vis[x->val]==nullptr)
                {
                    vis[x->val]=new Node(x->val);
                    q.push({x,vis[x->val]});
                }
                copy->neighbors.push_back(vis[x->val]);
            }
        }
        return vis[node->val];
    }
};