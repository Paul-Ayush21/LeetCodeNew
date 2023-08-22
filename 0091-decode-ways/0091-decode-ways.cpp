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
        vector<int> dp(s.size()+1,0);
        
        dp[s.size()]=1;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0') continue;
            int res=dp[i+1];
            if(i+1<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))) res+=dp[i+2];
            dp[i]=res;
        }
        return dp[0];
        // return f(0,s,dp);
    }
};