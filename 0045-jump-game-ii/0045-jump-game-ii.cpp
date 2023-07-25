class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size()-1) return 0;
        int take=1e6;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=1;i<=nums[ind];i++){
            take=min(take,1+f(ind+i,nums,dp));
        }
        return dp[ind]=take;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};