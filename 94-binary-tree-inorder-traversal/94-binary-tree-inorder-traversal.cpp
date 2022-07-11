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
    vector<int> inorderTraversal(TreeNode* root) {
        // morris inorder
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=nullptr)
        {
            if(curr->left==nullptr)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* ls=curr->left;
                while(ls->right!=nullptr && ls->right!=curr)
                {
                    ls=ls->right;
                }
                if(ls->right==curr)
                {
                    ls->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
                else
                {
                    ls->right=curr;
                    curr=curr->left;
                }
            }
        }
        return ans;
    }
};