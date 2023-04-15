class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int sis=grid[0].size();
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<sis;j++){
                if(i-1>=0 && j+1<sis && j-1>=0 && i+1<grid.size()){
                    int k=grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i][j]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                    maxi=max(k,maxi);
                }
            }
        }
        return maxi;
    }
};