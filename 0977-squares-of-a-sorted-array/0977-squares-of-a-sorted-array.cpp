class Solution {
public:
    
    int partition(vector<int> &nums,int low,int high){
        int part=nums[high];
        int j=low-1;
        for(int i=low;i<high;i++){
            if(nums[i]<part){
                j++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[j+1],nums[high]);
        return j+1;
    }
    
    
    void quick(vector<int> &nums,int low,int high){
        if(low<high){
            
            int pi=partition(nums,low,high);
            quick(nums,low,pi-1);
            quick(nums,pi+1,high);
        }
    }
//     int partition(vector<int> &arr, int low, int high)
// {

//     int pivot = arr[high];
 
//     int i = (low - 1);
 
//     for (int j = low; j <= high - 1; j++) {
 

//         if (arr[j] < pivot) {
 

//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }
 

// void quickSort(vector<int> &arr, int low, int high)
// {
//     if (low < high) {
 
//         int pi = partition(arr, low, high);

//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        quick(nums,0,nums.size()-1);
        return nums;
        
    }
};