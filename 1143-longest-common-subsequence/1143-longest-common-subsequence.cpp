class Solution {
public:
    int f(int i1,int i2,string &t1,string &t2,vector<vector<int>>& dp){
        if(i1<0 || i2<0){
            return 0;
        }
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        if(t1[i1]==t2[i2]){
            return dp[i1][i2]=1+f(i1-1,i2-1,t1,t2,dp);
        }
        return dp[i1][i2]=max(f(i1-1,i2,t1,t2,dp),f(i1,i2-1,t1,t2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return f(text1.size()-1,text2.size()-1,text1,text2,dp);
        
    }
};