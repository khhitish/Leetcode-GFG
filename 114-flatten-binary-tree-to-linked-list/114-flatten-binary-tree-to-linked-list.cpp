/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    /*Recursive O(n), O(n)
    void flattentree(TreeNode* node, TreeNode* &prev)
    {
        if(node==nullptr) return;
        flattentree(node->right,prev);
        flattentree(node->left,prev);
        node->right=prev;
        node->left=nullptr;
        prev=node;
    }
    */
    
    void helper(TreeNode* curr, TreeNode* &prev)
    {
        if(curr==nullptr) return;
        helper(curr->right,prev);
        helper(curr->left,prev);
        curr->right=prev;
        curr->left=nullptr;
        prev=curr;
    }
public:
    void flatten(TreeNode* root) {
        // //TreeNode* prev=nullptr;
        // //flattentree(root,prev); //recursive
        // /*iterative, O(n), O(n)
        // stack<TreeNode*> s;
        // if(root==nullptr) return;
        // s.push(root);
        // while(!s.empty())
        // {
        //     TreeNode* curr=s.top();
        //     s.pop();
        //     if(curr->right!=nullptr) s.push(curr->right);
        //     if(curr->left!=nullptr) s.push(curr->left);
        //     if(!s.empty())curr->right=s.top();
        //     curr->left=nullptr;
        // }
        // */
        // //Morris method O(n) time,O(1) space
        // while(root!=nullptr)
        // {
        //     if(root->left!=nullptr)
        //     {
        //         TreeNode* ls=root->left;
        //         while(ls->right!=nullptr)
        //         {
        //             ls=ls->right;
        //         }
        //         ls->right=root->right;
        //         root->right=root->left;
        //         root->left=nullptr;
        //     }
        //     root=root->right;
        // }
        TreeNode* prev=nullptr;
        helper(root,prev);
    }
};