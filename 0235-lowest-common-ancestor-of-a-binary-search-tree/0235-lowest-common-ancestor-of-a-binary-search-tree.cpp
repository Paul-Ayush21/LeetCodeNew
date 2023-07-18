/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* f(TreeNode* root,TreeNode* &p, TreeNode* &q){
        if(root==NULL) return NULL;
        int cur=root->val;
        if(cur>p->val && cur>q->val){
            return f(root->left,p,q);
        }
        if(cur<p->val && cur<q->val){
            return f(root->right,p,q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};