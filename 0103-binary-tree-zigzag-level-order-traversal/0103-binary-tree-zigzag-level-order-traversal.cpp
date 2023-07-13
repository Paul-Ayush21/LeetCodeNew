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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root==NULL) return res;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            
            vector<int> lvl(n);
            for(int i=0;i<n;i++){
                int index=flag?i:n-i-1;
                TreeNode* temp=q.front();
                q.pop();
                lvl[index]=temp->val;
                
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
                 
            }
            flag=!flag;
            res.push_back(lvl);
        }
        return res;
    }
    
};