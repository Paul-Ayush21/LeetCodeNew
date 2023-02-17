class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mr(numRows);
        // r[0][0]=213;
        // cout<<r[0][0];
        for(int i=0;i<numRows;i++){
            mr[i].resize(i+1);
            mr[i][0]=mr[i][i]=1;
            for(int j=1;j<i;j++){
                mr[i][j]=mr[i-1][j-1]+mr[i-1][j];
            }
        }
        return mr;
    }
};