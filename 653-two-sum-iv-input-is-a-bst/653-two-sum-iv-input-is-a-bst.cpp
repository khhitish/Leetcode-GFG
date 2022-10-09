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
//NAIVE: Get the inorder in a vector apply two pointers
//https://youtu.be/ssL3sHwPeb4
class BSTIterator{
private:
    stack<TreeNode*> s;
    bool reverse;
    void pushall(TreeNode* root)
    {
        while(root!=nullptr)
        {
            s.push(root);
            if(reverse==true)
            {
                root=root->right;
            }
            else root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool rev)
    {
        reverse=rev;
        pushall(root);
    }
    int next()
    {
        TreeNode* temp=s.top();
        s.pop();
        int data=temp->val;
        if(reverse==true)
        {
            pushall(temp->left);
        }
        else
        {
            pushall(temp->right);
        }
        return data;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next(), j=r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j>k)
            {
                j=r.next();
            }
            else
            {
                i=l.next();
            }
        }
        return false;
    }
};