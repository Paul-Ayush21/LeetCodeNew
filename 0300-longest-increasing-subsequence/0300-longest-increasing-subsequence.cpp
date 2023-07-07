class Solution {
public:
    int f(int ind,int prev,vector<int>& nums,vector<vector<int>>& dp){
        
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-2) return dp[ind][prev+1];
        int len=0+f(ind+1,prev,nums,dp);
        int len2=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            len2=1+f(ind+1,ind,nums,dp);
        }
        
        return dp[ind][prev+1]=max(len,len2);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-2));
        return f(0,-1,nums,dp);
    }
};