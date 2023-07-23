//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 private:
    void dfs(int row,int col,int baseRow,int baseCol,vector<vector<int>>& vis,vector<vector<int>>& grid,vector<pair<int,int>> &temp){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        temp.push_back({row-baseRow,col-baseCol});
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+dRow[i];
            int ncol=col+dCol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                dfs(nrow,ncol,baseRow,baseCol,vis,grid,temp);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>> temp;
                if(vis[i][j]==0 && grid[i][j]==1){
                    dfs(i,j,i,j,vis,grid,temp);
                    s.insert(temp);
                }
                
            }
        }
        // for(auto it:s){
        //     for(auto i:it){
        //         cout<<i.first<<" "<<i.second<<" ";
        //     }
        //     cout<<endl;
        // }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends