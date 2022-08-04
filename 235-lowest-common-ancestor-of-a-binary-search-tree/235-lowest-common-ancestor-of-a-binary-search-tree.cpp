/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x=p->val;
        int y=q->val;
        while(root!=nullptr)
        {
            int curr=root->val;
            if(x>curr && y>curr)
            {
                root=root->right;
            }
            else if(x<curr && y<curr)
            {
                root=root->left;
            }
            else
            {
                return root;
            }
        }
        return root;
    }
};