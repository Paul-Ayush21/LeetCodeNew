class Solution {
private:
    bool dfs(int src,vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int> &res){
        vis[src]=1;
        pathVis[src]=1;
        // cout<<4;
        
        for(auto it:adj[src]){
            if(vis[it]==0){
                
                if(dfs(it,adj,vis,pathVis,res)) return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        res.push_back(src);
        pathVis[src]=0;
        return false;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0), pathVis(numCourses,0), res;
        if(numCourses==1 ) {
            res.push_back(0);
            return res;
        }
        int n=prerequisites.size();
        vector<int> adj[numCourses];
        
        for(int i=0;i<n;i++){
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // for(auto it: adj){
        //     for(auto i : it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                // res.push_back(i);
                if(dfs(i,adj,vis,pathVis,res)==true){
                    res.clear();
                    return res;
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};