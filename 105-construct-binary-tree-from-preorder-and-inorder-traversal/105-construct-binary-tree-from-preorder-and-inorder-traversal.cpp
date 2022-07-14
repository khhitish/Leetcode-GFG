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
        TreeNode* helper(int prestart, int preend, int instart, int inend, vector<int> &preorder, vector<int> &inorder, unordered_map< int, int> &inmap)
        {
            if (prestart > preend) return nullptr;
            int inroot = inmap[preorder[prestart]];
            TreeNode *curr = new TreeNode(preorder[prestart]);
            curr->left = helper(prestart + 1, prestart + inroot - instart, instart, inroot - 1, preorder, inorder, inmap);
            curr->right = helper(prestart + inroot - instart + 1, preend, inroot + 1, inend, preorder, inorder, inmap);
            return curr;
        }
    public:
        TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            unordered_map<int, int> inmap;
            int n = inorder.size();
            for (int i = 0; i < n; i++)
            {
                inmap[inorder[i]] = i;
            }
            return helper(0, n - 1, 0, n - 1, preorder, inorder, inmap);
        }
};