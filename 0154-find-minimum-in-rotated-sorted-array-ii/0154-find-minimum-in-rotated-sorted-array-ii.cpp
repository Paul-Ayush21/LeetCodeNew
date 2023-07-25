class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=(high-low)/2+low;
            if(nums[low]<=nums[mid] && nums[mid]<=nums[high]) high--;
            else if(nums[low]>nums[mid]){
                high=mid;
                low=low+1;
            }
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            
        }
        return nums[low];
    }
};