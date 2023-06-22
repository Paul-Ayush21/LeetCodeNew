class Solution {
public:
    int f(int ind,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(ind==nums.size()){
            // cout<<target<<endl;
            if(target==0){
                // cout<<"here"<<endl;
                return 1;
            }
            // cout<<"HERE"<<endl;
            return 0;
        }
        if(dp[ind][target+1000]!=-1){return dp[ind][target+1000];}
        int plus=+nums[ind]+f(ind+1,nums,target+nums[ind],dp);
        int minus=-nums[ind]+f(ind+1,nums,target-nums[ind],dp);
        return dp[ind][target+1000]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        // cout<<sum;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum*2+1+2005,-1));
        return f(0,nums,target,dp);
        // return 0;
    }
};