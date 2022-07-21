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
    int dfs(TreeNode* root, int max_val)
    {
        if(root==nullptr) return 0;
        int ans=0;
        if(root->val>=max_val)
        {
            ans++;
        }
        ans+=dfs(root->left,max(max_val,root->val));
        ans+=dfs(root->right,max(max_val,root->val));
        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};