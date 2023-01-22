class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        
        if(!matrix.size()){
            cout<<"in";
            return false;
        }
        
        int low=0, high=(rowSize*colSize)-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid/colSize][mid%colSize]==target){
                return true;
            }
            if(matrix[mid/colSize][mid%colSize]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
//         int k;
//         bool res= false;
//         if(matrix.empty()==true){
//             return false;
//         }
//         for(int i=1;i<rowSize;i++){
//             if(target>=matrix[i][0] && target<=matrix[i-1][0]){
//                 k=i-1;
//             }
//         }
        
//         for(int i=0;i<colSize;i++){
//             if(target==matrix[k][i]){
//                 res=true;
//                 break;
//             }
//         }
        
//         return res;
    }
};