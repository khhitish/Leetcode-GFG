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
    // vector: isbst, maxvalue, minvalue,sum
private:
    vector<int> helper(TreeNode* root, int& ans)
    {
        if(root==nullptr)
        {
            return {1,INT_MIN,INT_MAX,0};
        }
        vector<int> l = helper(root->left,ans);
        vector<int> r = helper(root->right,ans);
        vector<int> returnv(4);
        if(l[0]==1 && r[0]==1)
        {
            if(l[1]<root->val && r[2]>root->val)
            {
                returnv[0]=1;
                ans=max(ans,l[3] + r[3] + root->val);
            }
        }
        returnv[1] = max(l[1],max(r[1],root->val));
        returnv[2] = min(l[2],min(r[2],root->val));
        returnv[3] = l[3] + r[3] + root->val;
        return returnv;
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans=INT_MIN;
        helper(root,ans);
        if(ans>=0) return ans;
        return 0;
    }
};