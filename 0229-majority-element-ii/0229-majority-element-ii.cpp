class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums1=-1,nums2=-1,cnt1=0,cnt2=0,numsSize=nums.size();
        
        for(auto it:nums){
            if(nums1==it){
                cnt1++;
            }
            else if(nums2==it){
                cnt2++;
            }
            else if(cnt1==0){
                nums1=it;
                cnt1++;
            }
            else if(cnt2==0){
                nums2=it;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ans;
        int count1=0,count2=0;
        for(int i=0;i<numsSize;i++){
            if(nums1==nums[i]){
                count1++;
            }
            else if(nums2==nums[i]){
                count2++;
            }
        }
        if(count1>numsSize/3){
            ans.push_back(nums1);
        }
        if(count2>numsSize/3){
            ans.push_back(nums2);
        }
        return ans;
    }
};