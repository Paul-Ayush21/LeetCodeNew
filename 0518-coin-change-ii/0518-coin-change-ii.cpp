class Solution {
public:
    int f(int ind,int target,int amount, vector<int>& coins,vector<vector<int>> & dp){
        
        if(ind==0){
                if(target%coins[ind]==0){
                    return 1;
                }
            return 0;
        }
        if(amount==0 && ind>=0){
            return 1;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        int take=0,notTake=0;
        if(coins[ind]<=target){
            take=f(ind,target-coins[ind],amount,coins,dp);
        }
        notTake=f(ind-1,target,amount,coins,dp);

        return dp[ind][target]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,amount,coins,dp);
    }
};