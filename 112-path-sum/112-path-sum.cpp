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
    bool dfs(TreeNode* root, int& target, int& sum)
    {
        if(root==nullptr) return false;
        if(root->left==nullptr && root->right==nullptr)
        {
            if(sum + root->val==target) return true;
        }
        sum+=root->val;
        bool l = dfs(root->left,target,sum);
        if(l==true) return true;
        bool r = dfs(root->right,target,sum);
        if(r==true) return true;
        sum-=root->val;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int target) {
        int sum=0;
        return dfs(root,target,sum);
    }
};