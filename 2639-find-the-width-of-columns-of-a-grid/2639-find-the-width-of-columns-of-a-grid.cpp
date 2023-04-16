class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        // int n=-1;
        // for(int i=0;i<grid.size();i++){
        //     n=max(n,grid[i].size());
        // }
        vector<int> fmap(grid[0].size(),-1);
       
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                string k=to_string(grid[i][j]);
                int k1=k.length();
               fmap[j]=max(fmap[j],k1);
            }
        }
        
        return fmap;
    }
};