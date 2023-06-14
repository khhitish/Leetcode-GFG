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
    int helper(TreeNode* root, int mini, int maxi) {
        if(root == nullptr) return INT_MAX;
        int ans = INT_MAX;
        if(mini!=-1) {
            ans = min(ans, root->val - mini);
        }
        if(maxi!=-1) {
            ans = min(ans, maxi - root->val);
        }
        ans = min(ans, helper(root->left,mini,root->val));
        ans = min(ans, helper(root->right,root->val, maxi));
        return ans;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        return helper(root,-1,-1);
    }
};