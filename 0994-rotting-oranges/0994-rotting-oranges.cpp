class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int iniCnt=0,maxTime=0,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    iniCnt++;
                }
            }
        }
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            maxTime=max(t,maxTime);
            for(int i=0;i<4;i++){
                int nrow=r+dRow[i];
                int ncol=c+dCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)                 {
                    vis[nrow][ncol]=2;
                    cnt++;
                    q.push({{nrow,ncol},t+1});
                }
            }
            
        }
        if(cnt!=iniCnt) return -1;
        return maxTime;
    }
};