class Solution {
public:
    
    int f(int ind,int end,int n,int x,vector<vector<int>> &dp){
        if(n==0) return 1;
        if(ind>end){
            if(n==0) return 1;
            return 0;
        }
        
        if(dp[ind][n]!=-1) return dp[ind][n];
        int take=0;
        if(n-pow(ind,x)>=0){
            take=f(ind+1,end,n-pow(ind,x),x,dp);
        }
        int notTake=f(ind+1,end,n,x,dp);
        
        return dp[ind][n]=(take+notTake)%int(1e9+7);
    }
    int numberOfWays(int n, int x) {
        
        int num;
        for(int i=1;i<=n;i++){
            if(pow(i,x)>n){
                num=i-1;
                break;
            }
        }
        vector<vector<int>> dp(num+2,vector<int>(n+2,-1));
        // cout<<num<<endl;
        return f(1,num,n,x,dp);
    }
};