class Solution {
public:
    int f(int i,int j1, int j2,vector<vector<int>> & grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=grid[0].size()||j2<0||j2>=grid[0].size()){
            return -1e7;
        }
        if(i==grid.size()-1){
            if(j1==j2){return grid[i][j1];}
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        int maxi=-1e6;
        if(dp[i][j1][j2]!=-1){return dp[i][j1][j2];}
        for(int d1=-1;d1<2;d1++){
            for(int d2=-1;d2<2;d2++){
                int value=0;
                if(j1==j2){value=grid[i][j1];}
                else{value=grid[i][j1]+grid[i][j2];}
                value+=f(i+1,j1+d1,j2+d2,grid,dp);
                maxi=max(value,maxi);
                
            }
        }
        return dp[i][j1][j2]= maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return f(0,0,grid[0].size()-1,grid,dp);
    }
};