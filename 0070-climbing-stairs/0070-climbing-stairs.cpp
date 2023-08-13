class Solution {
public:
    int f(int n,vector<long long>& dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp) + f(n-2,dp);
    }
    int climbStairs(int n) {
        vector<long long> dp(n+1,-1);
        return f(n,dp);
        
//         dp[0]=1;
//         dp[1]=1;
        
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
        
//         return dp[n];
        
    }
};