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
    TreeNode* f(int inStart,int inEnd,int postStart,int postEnd,vector<int>& inorder,vector<int>& postorder, map<int,int>& smap){
        if(inStart>inEnd || postStart>postEnd) return NULL;
        
        TreeNode* node= new TreeNode(postorder[postEnd]);
        
        int ind=smap[postorder[postEnd]];
        int inLeft=ind-inStart;
        
        node->left=f(inStart,ind-1,postStart,postStart+inLeft-1,inorder,postorder,smap);
        node->right=f(ind+1,inEnd,postStart+inLeft,postEnd-1,inorder,postorder,smap);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;   
        map<int,int> smap;
        for(int i=0;i<inorder.size();i++){
            smap[inorder[i]]=i;
        }
        
        return f(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder,smap);
    }
};