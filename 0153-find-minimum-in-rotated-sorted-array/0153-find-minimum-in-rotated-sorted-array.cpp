class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        
        while(low<high){
            int mid=(high-low)/2+low;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            if(nums[low]<nums[high]) return nums[low];
            
            if(nums[low]>nums[mid]) high=mid;
            else low=mid+1;
        }
        return nums[low];
    }   
};