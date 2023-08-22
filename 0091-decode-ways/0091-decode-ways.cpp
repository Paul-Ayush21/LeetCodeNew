class Solution {
public:
    
    int f(int ind, string& s,vector<int>& dp){
        if(ind==s.size()) return 1;
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res=f(ind+1,s,dp);
        if(ind+1<s.size() && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<'7'))) res+=f(ind+2,s,dp);
        return dp[ind]=res;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return f(0,s,dp);
    }
};