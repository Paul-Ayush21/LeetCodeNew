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
    TreeNode* f(TreeNode* root,map<TreeNode*,TreeNode*>& pMap,int target){
        TreeNode* res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->val==target){res=node;}
                if(node->left){
                    q.push(node->left);
                    pMap[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    pMap[node->right]=node;
                }
            }
        }
        return res;
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> pMap;
        TreeNode* found=f(root,pMap,start);
        queue<TreeNode*> q;
        map<TreeNode*,bool> vMap;
        q.push(found);
        vMap[found]=true;
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            int flag=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vMap[node->left]){
                    // cout<<node->left->val<<" ";
                    q.push(node->left);
                    vMap[node->left]=true;
                    flag=1;
                }
                if(node->right && !vMap[node->right]){
                    // cout<<node->right->val<<" ";
                    q.push(node->right);
                    vMap[node->right]=true;
                    flag=1;
                }
                // cout<<"parent: "<<pMap[node]->val<<" ";
                if(pMap[node] && !vMap[pMap[node]]){
                    // cout<<pMap[node]->val<<" ";
                    q.push(pMap[node]);
                    vMap[pMap[node]]=true;
                    flag=1;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};