class Solution {
public:
    int f(int i1,int i2,string &t1,string &t2,vector<vector<int>>& dp){
        if(i1==0 || i2==0){
            return 0;
        }
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        if(t1[i1-1]==t2[i2-1]){
            return dp[i1][i2]=1+f(i1-1,i2-1,t1,t2,dp);
        }
        return dp[i1][i2]=max(f(i1-1,i2,t1,t2,dp),f(i1,i2-1,t1,t2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        // return f(text1.size(),text2.size(),text1,text2,dp);
        
        for(int i=0;i<=text1.size();i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=text2.size();i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        
        int i=text1.size(),j=text2.size();
        string f="";
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                f=text1[i-1]+f;
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        cout<<f;
        return dp[text1.size()][text2.size()];
    }
};