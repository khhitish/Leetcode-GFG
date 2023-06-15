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
public:
    int maxLevelSum(TreeNode* root) {
        int currLevel = 1, currSum = 0;
        int ans = 1, maxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode* currNode = q.front();
                q.pop();
                currSum+=currNode->val;
                if(currNode->left!=nullptr) q.push(currNode->left);
                if(currNode->right!=nullptr) q.push(currNode->right);
            }
            if(currSum > maxSum) {
                maxSum = currSum;
                ans = currLevel;
            }
            currSum=0;
            currLevel++;
        }
        return ans;
    }
};