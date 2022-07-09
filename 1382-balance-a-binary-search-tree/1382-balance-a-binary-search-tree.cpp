/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:
        void store_inorder(TreeNode *root, vector<int> &inorder)
        {
            if (root == nullptr) return;
            store_inorder(root->left, inorder);
            inorder.push_back(root->val);
            store_inorder(root->right, inorder);
        }
    TreeNode* build_tree(vector<int> &inorder, int low, int high)
    {
        if(low>high) return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode *curr = new TreeNode(inorder[mid]);
        curr->left = build_tree(inorder, low, mid - 1);
        curr->right = build_tree(inorder, mid + 1, high);
        return curr;
    }
    public:
        TreeNode* balanceBST(TreeNode *root)
        {
            vector<int> inorder;
            store_inorder(root, inorder);
            int n = inorder.size();
            TreeNode *ans = build_tree(inorder, 0, n - 1);
            return ans;
        }
};