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
    int helper(TreeNode* root, unordered_map<int,int>& mp)
    {
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr)
        {
            mp[root->val]++;
            int oddcnt=0,sz=0;
            for(auto&it : mp)
            {
                if(it.second%2==1)oddcnt++;
                sz+=it.second;
            }
            mp[root->val]--;
            if(mp.count(root->val)==0)mp.erase(root->val);
            if(sz%2==1 && oddcnt==1)return 1;
            else if(sz%2==0 && oddcnt==0) return 1;
            return 0;
        }
        mp[root->val]++;
        int ans=0;
        ans+=helper(root->left,mp);
        ans+=helper(root->right,mp);
        mp[root->val]--;
        if(mp.count(root->val)==0)mp.erase(root->val);
        return ans;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        return helper(root,mp);
    }
};