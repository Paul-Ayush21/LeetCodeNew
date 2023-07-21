class Solution {
public:
    void dfs(vector<int> adj[],vector<int>& vis,int node){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]!=1){
                vis[it]=1;
                dfs(adj,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<int> adj[n];
        int m=isConnected[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1 && i!=j){
                    // cout<<i<<" "<<j<<endl;
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        
        return cnt;
    }
};