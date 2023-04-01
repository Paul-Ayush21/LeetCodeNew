class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int end=n*n-1;
        int sCol=0,sRow=0,eCol=n-1,eRow=n-1,count=0,value=1;
        vector<vector<int>> res(n,vector<int>(n,0));
        while(count<=end){
            for(int i=sCol;count<=end && i<=eCol;i++){
                res[sRow][i]=value;
                value++;
                count++;
            }
            sRow++;
            for(int i=sRow;count<=end && i<=eRow;i++){
                res[i][eCol]=value;
                value++;
                count++;
            }
            eCol--;
            for(int i=eCol;count<=end && i>=sCol;i--){
                res[eRow][i]=value;
                value++;
                count++;
            }
            eRow--;
            for(int i=eRow;count<=end && i>=sRow;i--){
                res[i][sCol]=value;
                value++;
                count++;
            }
            sCol++;
        }
        return res;
    }
};