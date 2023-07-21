class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
            // cout<<endl;
        // }
        // cout<<endl;
        int dRow[]={-1,0,1,0};
        int dCol[]={0,+1,0,-1};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int distance=q.front().second;
            // cout<<i<<" "<<j<<" "<<distance<<endl;
            q.pop();
            dis[i][j]=distance;
            for(int k=0;k<4;k++){
                int nrow=i+dRow[k];
                int ncol=j+dCol[k];
                // cout<<i<<" "<<j<<" "<<distance<<" "<<nrow<<" "<<ncol<<endl;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},distance+1});
                }
            }
            // cout<<endl;
        }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dis;
    }
};