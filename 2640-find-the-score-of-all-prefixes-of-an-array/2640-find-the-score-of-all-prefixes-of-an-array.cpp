class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans(nums.size(),0);
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            
            long long cover=nums[i]+maxi;
            if(i==0) ans[0]=cover;
            else{
                ans[i]=ans[i-1]+cover;
            }
            
        }
        return ans;
    }
};