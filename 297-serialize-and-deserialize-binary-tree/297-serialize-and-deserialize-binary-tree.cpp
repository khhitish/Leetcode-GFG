/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push({root});
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr==nullptr)
                {
                    ans+="#,";
                    continue;
                }
                else ans+=to_string(curr->val) + ',';
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        string value;
        stringstream x(data);
        getline(x,value,',');
        TreeNode* root=new TreeNode(stoi(value));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            getline(x,value,',');
            if(value!="#")
            {
                curr->left=new TreeNode(stoi(value));
                q.push(curr->left);
            }
            getline(x,value,',');
            if(value!="#")
            {
                curr->right=new TreeNode(stoi(value));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));