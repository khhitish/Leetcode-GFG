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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto p = q.front();
                q.pop();
                int x = p.second.first;
                int y = p.second.second;
                TreeNode *curr = p.first;
                m[x][y].insert(curr->val);
                if(curr->left) q.push({curr->left,{x-1,y+1}});
                if(curr->right) q.push({curr->right,{x+1,y+1}});
            }
        }
        for(auto &it : m)
        {
            vector<int> temp;
            for(auto &x : it.second)
            {
                temp.insert(temp.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};