class Solution {
public:
    long long f(int ind,int odd,int x,vector<int>& nums,vector<vector<long long>>& dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][odd]!=-1) return dp[ind][odd];
        long long take=nums[ind]+f(ind +1,nums[ind]&1,x,nums,dp);
        long long notTake=f(ind+1,odd,x,nums,dp);
        if((nums[ind]&1)!=odd) take-=x;
        return dp[ind][odd]=max(take,notTake);
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size(),(vector<long long>(2,-1)));
        return nums[0]+f(1,nums[0]&1,x,nums,dp);
    }
};