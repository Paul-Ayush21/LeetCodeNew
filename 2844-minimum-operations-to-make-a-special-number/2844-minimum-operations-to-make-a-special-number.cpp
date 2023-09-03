class Solution {
public:
    
    int f(int ind,int mod, string &num,vector<vector<int>> &dp){
        if(ind==num.size()){
            if(mod%25==0){
                return 0;
            }
            return 1e8;
        }
        
        if(dp[ind][mod]!=-1) return dp[ind][mod];
        
        int k=num[ind]-'0';
        int take=f(ind+1,(mod*10 + k)%25,num,dp);
        int notTake=1+f(ind+1,mod,num,dp);
        
        return dp[ind][mod]=min(take,notTake);
    }
    int minimumOperations(string num) {
        vector<vector<int>> dp(num.size(),vector<int>(26,-1));
        return f(0,0,num,dp);
    }
};