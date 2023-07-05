class Solution {
public:
    
    int f(int i,int j, string &s, string &t,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=f(i-1,j-1,s,t,dp);
        }
        return dp[i][j]= 1+min(min(f(i,j-1,s,t,dp),f(i-1,j,s,t,dp)),f(i-1,j-1,s,t,dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return f(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};