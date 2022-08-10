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
    TreeNode* dfs(int left, int right, vector<int>& nums)
    {
        if(left > right) return nullptr;
        int mid = left + (right - left)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = dfs(left,mid-1,nums);
        curr->right = dfs(mid+1,right,nums);
        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left= 0, right = nums.size()-1;
        return dfs(left,right,nums);
    }
};