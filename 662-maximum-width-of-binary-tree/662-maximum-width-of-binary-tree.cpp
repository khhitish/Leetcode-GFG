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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty())
        {
            int n=q.size();
            long long first = q.front().second;
            long long last = q.back().second;
            while(n--)
            {
                auto p=q.front();
                q.pop();
                long long i = p.second;
                i-=first;
                TreeNode* curr=p.first;
                if(curr->left) q.push({curr->left,2*i+1});
                if(curr->right) q.push({curr->right,2*i+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};