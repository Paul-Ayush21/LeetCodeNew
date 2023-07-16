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
    void in(TreeNode* root, vector<int>& res){
        if(root==NULL) return;
        in(root->left,res);
        res.push_back(root->val);
        in(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // in(root,res);
        // return res;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                if(prev->right==curr){
                    prev->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return res;
        
    }
};