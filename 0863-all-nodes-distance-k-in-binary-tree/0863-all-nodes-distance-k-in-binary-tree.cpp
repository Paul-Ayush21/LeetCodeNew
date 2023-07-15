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
    
    void f(TreeNode* root,map<TreeNode*,TreeNode*>& pMap){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
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
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parentMap;
        f(root,parentMap);
        queue<TreeNode*> q;
        map<TreeNode*,bool> vMap;
        q.push(target);
        vMap[target]=true;
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            if(cnt==k) break;
            cnt++;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vMap[node->left]){
                    q.push(node->left);
                    vMap[node->left]=true;
                }
                if(node->right && !vMap[node->right]){
                    q.push(node->right);
                    vMap[node->right]=true;
                }
                if(parentMap[node] && !vMap[parentMap[node]]){
                    q.push(parentMap[node]);
                    vMap[parentMap[node]]=true;
                }
            }
        }
        vector<int> ans;
        // cout<<q.size();
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};