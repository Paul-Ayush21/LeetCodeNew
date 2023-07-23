class Solution {
private:
    void bfs(int drow[],int dcol[], vector<vector<int>>& vis, vector<vector<int>>& grid,queue<pair<int,int>> &q){
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                vis[0][j]=1;
                q.push({0,j});
            }
            if(grid[n-1][j]==1){
                vis[n-1][j]=1;
                q.push({n-1,j});
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        bfs(drow,dcol,vis,grid,q);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};