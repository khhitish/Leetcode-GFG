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
    TreeNode* helper(TreeNode* p)
    {
        if(p->left==nullptr) return p->right;
        else if(p->right==nullptr) return p->left;
        else
        {
            TreeNode* l=p->left;
            TreeNode* r=p->right;
            
            // while(l->right!=nullptr) l=l->right;
            // l->right = r;
            // return p->left;
            
            //or
            while(r->left!=nullptr) r=r->left;
            r->left=l;
            return p->right;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(root->val==key) return helper(root);
        TreeNode* p=root;
        while(p!=nullptr)
        {
            if(p->val<key)
            {
                if(p->right!=nullptr && p->right->val == key)
                {
                    p->right = helper(p->right);
                }
                else
                {
                    p=p->right;
                }
            }
            else
            {
                if(p->left!=nullptr && p->left->val == key)
                {
                    p->left = helper(p->left);
                }
                else
                {
                    p=p->left;
                }
            }
        }
        return root;
    }
};