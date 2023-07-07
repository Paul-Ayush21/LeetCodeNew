class Solution {
public:
    int f(int ind,int buy, vector<int>& prices,vector<vector<int>>& dp){
        
        if(ind>prices.size()-1){
            return 0;
        }
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=INT_MIN;
        if(buy){
            profit=max(-prices[ind]+f(ind+1,0,prices,dp),0+f(ind+1,1,prices,dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1,1,prices,dp),0+f(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        // return f(0,1,prices,dp);
        int n=prices.size();
        for(int i=0;i<2;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int profit=0;
                if(j){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];
    }
};