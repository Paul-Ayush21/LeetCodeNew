class Solution {
public:
    int f(int ind,int n,vector<long long>& dp){
        if(ind==0) return 1;
        
        int m1,m2;
        if(ind-1>=0){
            m1=f(ind-1,n,dp);
        }
        if(ind-2>=0){
            m2=f(ind-2,n,dp);
        }
        return dp[ind]=m1+m2;
        
    }
    int climbStairs(int n) {
        vector<long long> dp(n+1,-1);
        // return f(n,n,dp);
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
        dp[n] = 1;
        dp[n-1]=1;
        
        for(int i=n-2;i>0;i--){
                int m1,m2;
                if(i+1<n-1){
                    m1=dp[i+1];
                }
                if(i+2<n-1){
                    m2=dp[i+2];
                }
                dp[i]=m1+m2;
        }
        return dp[1];
    }
};