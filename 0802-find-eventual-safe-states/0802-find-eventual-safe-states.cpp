class Solution {
public:
    bool dfs(int src,vector<vector<int>>& graph,vector<int>& vis, vector<int>& pathVis, vector<int>& count){
        vis[src]=1;
        pathVis[src]=1;
        count[src]=0;
        
            for(int j=0;j<graph[src].size();j++){
                if(vis[graph[src][j]]==0){
                    if(dfs(graph[src][j],graph,vis,pathVis,count)==true) return true;
                    }
                else if(pathVis[graph[src][j]]==1){
                    return true;
                }
            }
        
        count[src]=1;
        pathVis[src]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // vector<int> adj[n];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<graph[i].size();j++){
        //         adj[i].push_back(j);
        //     }
        // }
        int n=graph.size();
        vector<int> vis(n,0),ans;
        vector<int> pathVis(n,0), count(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,graph,vis,pathVis,count);
            }
        }
        for(int i=0;i<n;i++){
            if(count[i]==1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};