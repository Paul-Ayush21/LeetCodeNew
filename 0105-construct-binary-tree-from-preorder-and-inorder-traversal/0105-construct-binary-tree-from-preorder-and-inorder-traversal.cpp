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
    
    TreeNode* f(int preStart,int preEnd,int inStart,int inEnd,vector<int>& preorder,vector<int>& inorder, map<int,int> &smap){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode* node=new TreeNode(preorder[preStart]);
        // node->val=preorder[preStart];
        
        int ind=smap[preorder[preStart]];
        int leftInd=ind-inStart;
        
        node->left=f(preStart+1,preStart+leftInd,inStart,ind-1,preorder,inorder,smap);
        node->right=f(preStart+leftInd+1,preEnd,ind+1,inEnd,preorder,inorder,smap);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> smap;
        
        for(int i=0;i<inorder.size();i++){
            smap[inorder[i]]=i;
        }
        
        return f(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder,smap);
        
    }
};