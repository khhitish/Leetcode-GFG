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
    bool dfs(TreeNode* root1, TreeNode* root2)
    {
        if(root1==nullptr && root2==nullptr) return true;
        else if(root1==nullptr || root2==nullptr) return false;
        if(root1->val!=root2->val) return false;
        if(dfs(root1->left,root2->right)==false) return false;
        if(dfs(root1->right,root2->left)==false) return false;
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};