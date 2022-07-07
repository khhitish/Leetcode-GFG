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
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/1654181/C++PythonJava-Simple-Solution-w-Images-and-Explanation-or-BFS-+-DFS-+-O(1)-Optimized-BFS
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        //dfs(root); 
        if(root->left!=nullptr)// both children exist
        {
            root->left->next=root->right;
            if(root->next!=nullptr)
            {
                root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
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