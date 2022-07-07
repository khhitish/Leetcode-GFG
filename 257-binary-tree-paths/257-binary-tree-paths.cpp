/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:
        void helper(TreeNode *root, string temp, vector<string> &ans)
        {
            if (root == nullptr) return;
            if (root->left == nullptr && root->right == nullptr)
            {
                ans.push_back(temp + to_string(root->val));
                return;
            }
            helper(root->left, temp + to_string(root->val) + "->", ans);
            helper(root->right, temp + to_string(root->val) + "->", ans);
        }
    public:
        vector<string> binaryTreePaths(TreeNode *root)
        {
            vector<string> ans;
            string temp;
            helper(root, temp, ans);
            return ans;
        }
};