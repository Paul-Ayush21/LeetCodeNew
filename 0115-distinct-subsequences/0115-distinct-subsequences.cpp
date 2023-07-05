class Solution {
public:
    int f(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(j==0) return 1;
        if(i==0) return 0;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]){
            return dp[i][j]= (f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp));
        }
        else{
            return dp[i][j]=f(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(s.size()+1,vector<double>(t.size()+1,0));
        // int k=f(s.size(),t.size(),s,t,dp);
        // return k;
        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=t.size();i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]);
                    // cout<<dp[i][j]<<endl;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                    // cout<<dp[i][j]<<endl;
                }
            }
        }
        // for(int i=0;i<=s.size();i++){
        //     for(int j=0;j<=t.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[s.size()][t.size()];
    }
    
};