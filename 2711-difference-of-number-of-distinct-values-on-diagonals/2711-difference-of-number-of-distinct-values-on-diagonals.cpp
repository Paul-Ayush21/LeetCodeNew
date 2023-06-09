class Solution {
public:
    int fun(vector<vector<int>>& grid, int r, int c){
        // cout<<"Row: "<<r<<endl;
        // cout<<"Column: "<<c<<endl;
        int tempR=r,tempC=c;
        int rowSize=grid.size();
        int colSize=grid[0].size();
        set<int> left;
        set<int> right;
        while(tempR-1>=0 && tempC-1>=0){
            tempR-=1;
            tempC-=1;
            // cout<<"Left No: "<<grid[tempR][tempC]<<endl;
            left.insert(grid[tempR][tempC]);
        }
       
        while(r+1<rowSize && c+1<colSize){
            r+=1;
            c+=1;
            // cout<<"Right No: "<<grid[r][c]<<endl;
            right.insert(grid[r][c]);
        }
        
        int b=(left.size()-right.size());
        // cout<<"Left: "<<left.size()<<endl;
        // cout<<"Right: "<<right.size()<<endl;
        // cout<<endl;
        if(b<0){
            return b*-1;
        }
        return b;
        
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int k=fun(grid,i,j);
                res[i][j]=k;
            }
        }
        return res;
    }
};