class Solution {
public:
    int f(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(ind==coins.size()-1){
               if(amount%coins[ind]==0){
                   return 1;
               } 
            return 0;
        }    
       
        if(dp[amount][ind]!=-1) return dp[amount][ind];
       int nottake=f(ind+1,amount,coins,dp);
        int take=0;
        if(coins[ind]<=amount){
            take=f(ind,amount-coins[ind],coins,dp);
        }
        return dp[amount][ind]=take+nottake;
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        return f(0,amount,coins,dp);
    }
};