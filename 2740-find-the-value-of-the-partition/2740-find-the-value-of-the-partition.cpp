class Solution {
public:
//     void fin(int i,vector<int>& nums,vector<int>& nums1,vector<int> &nums2,vector<int>& kim){
//         if(i==nums.size()){
//             int maxi=*max_element(nums1.begin(),nums1.end());
//             int mini=*min_element(nums2.begin(),nums2.end());
//             int k=abs(maxi-mini);
//             if(k<kim[0]){
//                 kim.pop_back();
//                 kim.push_back(k);
//             }
//             return;
//         }
        
//             nums1.push_back(nums[i]);
//             fin(i+1,nums,nums1,nums2,kim);
//             nums1.pop_back();
//             fin(i+1,nums,nums1,nums2,kim);
//             nums2.push_back(nums[i]);
//             fin(i+1,nums,nums1,nums2,kim);
//             nums2.pop_back();
//             fin(i+1,nums,nums1,nums2,kim);
        
//     }
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            ans=min(ans,abs(nums[i]-nums[i+1]));
        }
        return ans;
            
    }
};