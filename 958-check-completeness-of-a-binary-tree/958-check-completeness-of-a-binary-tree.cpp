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
    int count(TreeNode* root)
    {
        if(root==nullptr) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    bool iscbt(TreeNode* root, int i, int cnt)
    {
        if(root==nullptr) return true;
        if(i>=cnt) return false;
        return (iscbt(root->left,2*i+1,cnt) && iscbt(root->right,2*i +2,cnt));
    }
public:
    bool isCompleteTree(TreeNode* root) {
        return iscbt(root,0,count(root));
    }
};