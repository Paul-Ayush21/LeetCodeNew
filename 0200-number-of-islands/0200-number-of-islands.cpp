class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==-1 && j==0 || i==0 && j==1 || i==1 && j==0 || i==0&& j==-1){
                    int nrow=row+i;
                    int ncol=col+j;

                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && 
                       grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                        cout<<"i: "<<nrow<<" j: "<<ncol<<endl;
                        dfs(nrow,ncol,vis,grid);
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};