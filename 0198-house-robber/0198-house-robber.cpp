class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){return dp[ind];}
        int take=nums[ind]+f(ind+2,nums,dp);
        int not_take=0+f(ind+1,nums,dp);
        return dp[ind]= max(take,not_take);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};