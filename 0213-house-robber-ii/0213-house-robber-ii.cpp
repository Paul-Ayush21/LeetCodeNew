class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind]+f(ind+2,nums,dp);
        int notTake=f(ind+1,nums,dp);
        
        return dp[ind]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> A,B;
        vector<int> dpA(nums.size()-1,-1);
        vector<int> dpB(nums.size()-1,-1);
        copy(nums.begin(),nums.begin()+n-1,back_inserter(A));
        copy(nums.begin()+1,nums.end(),back_inserter(B));
        return max(f(0,A,dpA),f(0,B,dpB));
    }
};