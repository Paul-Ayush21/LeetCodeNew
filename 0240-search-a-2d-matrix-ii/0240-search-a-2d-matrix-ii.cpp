class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return false;
        }
        int row=0;
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        int col=colSize-1;
        while(row<=rowSize-1 && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};