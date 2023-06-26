class Solution {
public:
    int f(int r1,int c1,int r2,int c2,int n,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>> &dp){
        if(r1>n-1 || r2>n-1 || c1>n-1 || c2>n-1 || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return -1e7;
        }   
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        int cherr=0;
        if(r1==r2 && c1==c2){
            cherr+=grid[r1][c1];
        }
        else{
            cherr+= grid[r1][c1]+grid[r2][c2];
        }
        if(dp[r1][c1][r2][c2]!=-1){
            return dp[r1][c1][r2][c2];
        }
        int m1=0,m2=0,m3=0,m4=0;
        m1+=f(r1+1,c1,r2+1,c2,n,grid,dp);
        m2+=f(r1+1,c1,r2,c2+1,n,grid,dp);
        m3+=f(r1,c1+1,r2,c2+1,n,grid,dp);
        m4+=f(r1,c1+1,r2+1,c2,n,grid,dp);
        
        cherr+=max(max(m1,m2),max(m3,m4));
        return dp[r1][c1][r2][c2]=cherr;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        long long k=f(0,0,0,0,grid.size(),grid,dp);
        if(k<0){
            return 0;
        }
        else{
            return k;
        }
    }
};