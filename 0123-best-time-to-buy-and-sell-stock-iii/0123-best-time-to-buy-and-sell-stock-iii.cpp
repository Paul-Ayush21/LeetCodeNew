class Solution {
public:
    int f(int ind,int buy, int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(cap==0 || ind>prices.size()-1) return 0;
        
        int profit=INT_MIN;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            profit=max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap] =profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return f(0,1,2,prices,dp);
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<=2;j++){
                dp[n][i][j]=0;
            }
        }
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=INT_MIN;
                    if(buy){
                        profit=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                    }
                    else{
                        profit=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] =profit;
                }
            }
        }
        return dp[0][1][2];
    }
};