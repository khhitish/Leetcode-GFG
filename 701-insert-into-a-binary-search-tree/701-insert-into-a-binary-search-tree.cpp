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
public:
    TreeNode* insertIntoBST(TreeNode* root, int target) {
        // TreeNode* curr=root;
        // TreeNode *node = new TreeNode(target);
        // if(root==nullptr) return node;
        // while(true)
        // {
        //     if(curr->val < target)
        //     {
        //         if(curr->right!=nullptr) curr=curr->right;
        //         else
        //         {
        //             curr->right = node;
        //             break;
        //         }
        //     }
        //     else
        //     {
        //         if(curr->left!=nullptr) curr=curr->left;
        //         else
        //         {
        //             curr->left=node;
        //             break;
        //         }
        //     }
        // }
        // return root;
        
        //recursive
        if(root==nullptr)
        {
            TreeNode* p=new TreeNode(target);
            return p;
        }
        if(root->val < target)
        {
            root->right = insertIntoBST(root->right,target);
        }
        else
        {
            root->left=insertIntoBST(root->left,target);
        }
        return root;
    }
};