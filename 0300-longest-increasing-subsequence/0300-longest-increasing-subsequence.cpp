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
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        // return f(0,-1,nums,dp);
        
        // for(int i=0;i<=nums.size();i++){
        //     dp[nums.size()][i]=0;
        // }
        
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int len=0+dp[i+1][j+1];
                int len2=0;
                if(j==-1 || nums[i]>nums[j]){
                    len2=1+dp[i+1][i+1];
                }

                dp[i][j+1]=max(len,len2);
            }
        }
        return dp[0][0];
    }
};