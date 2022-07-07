/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void dfs(Node* root)
    {
        if(root->left!=nullptr)// both children exist
        {
            root->left->next=root->right;
            if(root->next!=nullptr)
            {
                root->right->next = root->next->left;
            }
            dfs(root->left);
            dfs(root->right);
        }
        
    }
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        dfs(root); 
        return root;
        // queue<Node*> q;
        // q.push(root);
        // while(!q.empty())
        // {
        //     int n=q.size();
        //     Node* rnode=nullptr;
        //     while(n--)
        //     {
        //         Node* curr=q.front();
        //         q.pop();
        //         curr->next=rnode;
        //         rnode=curr;
        //         if(curr->right) q.push(curr->right);
        //         if(curr->left) q.push(curr->left);
        //     }
        // }
        // return root;
    }
};