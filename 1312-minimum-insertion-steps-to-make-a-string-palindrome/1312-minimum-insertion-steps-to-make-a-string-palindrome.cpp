class Solution {
public:
    
    int f(int i,int j,string &s, string &t,vector<vector<int>> &dp){
        
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+f(i-1,j-1,s,t,dp);  
        }
        
        return dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
        
        
    }
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        int k=f(s.size()-1,t.size()-1,s,t,dp);
        return s.size()-k;
    }
};