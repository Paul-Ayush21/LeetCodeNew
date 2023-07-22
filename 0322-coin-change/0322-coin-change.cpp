class Solution {
public:
    
    int f(vector<int>& coins,int amount,vector<int>& dp){
        if(amount<0) return 1e4;
        if(amount==0) return 0;
        
        
        if(dp[amount]!=-1) return dp[amount];
        int ans=1e9;
        for(auto it: coins){
            int m=f(coins,amount-it,dp);
            if(m!=1e4){
                ans=min(ans,m+1);
            }
            
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=f(coins,amount,dp);
        if(ans>=1e7) return -1;
        return ans;
    }
};