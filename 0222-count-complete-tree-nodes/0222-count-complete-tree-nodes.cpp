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
    int lh1(TreeNode* node){
        if(!node) return 0;
        return 1+lh1(node->left);
    }
    int rh1(TreeNode* node){
        if(!node) return 0;
        return 1+rh1(node->right);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh=lh1(root);
        int rh=rh1(root);
        
        if(lh==rh) return (1<<lh)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};