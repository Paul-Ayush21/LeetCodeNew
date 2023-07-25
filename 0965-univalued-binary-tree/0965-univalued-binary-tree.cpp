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
    void in(int src,int &k,TreeNode* root){
        if(root==NULL) return;
        in(src,k,root->left);
        if(root->val!=src) k=1;
        in(src,k,root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        int k=0;
        in(root->val,k,root);
        if(k) return false;
        return true;
    }
};