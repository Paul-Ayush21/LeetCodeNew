class Solution {
public:
    int f(int ind,vector<int>& prices,int fee,bool status,vector<vector<int>>& dp){
        if(ind==prices.size()){
            return 0;
        }
        
        if(dp[ind][status]!=-1)return dp[ind][status];
        int prof;
        if(status==false){
             prof=max((0+f(ind+1,prices,fee,false,dp)),(-prices[ind]+f(ind+1,prices,fee,true,dp)));
        }
        else{
             prof=max((0+f(ind+1,prices,fee,true,dp)),(prices[ind]-fee+f(ind+1,prices,fee,false,dp)));
        }
        return dp[ind][status]=prof;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,prices,fee,false,dp);
    }
};