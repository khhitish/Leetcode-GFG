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
    void helper(TreeNode* root, long long& sum, int& ans, int& target, unordered_map<long long,int>& pref)
    {
        if(root==nullptr) return;
        sum+=root->val;
        if(pref.count(sum-target)>0)
        {
            ans+=pref[sum-target];
        }
        pref[sum]++;
        helper(root->left,sum,ans,target,pref);
        helper(root->right,sum,ans,target,pref);
        pref[sum]--;
        if(pref[sum]==0)pref.erase(sum);
        sum-=root->val;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> pref;
        long long sum=0;
        int ans=0;
        pref[0]=1;
        helper(root,sum,ans,targetSum,pref);
        return ans;
    }
};