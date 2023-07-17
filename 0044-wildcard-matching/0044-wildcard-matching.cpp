class Solution {
public:
    
    bool f(int sInd,int pInd,string s,string p,vector<vector<int>> &dp){
        
        if(sInd==0 && pInd>0){
            for(int i=1;i<pInd;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(pInd==0 && sInd>0) return false;
        if(sInd==0 && pInd==0) return true;
        
        if(dp[sInd][pInd]!=-1) return dp[sInd][pInd];
        
        if(s[sInd-1]==p[pInd-1] || p[pInd-1]=='?'){
            return dp[sInd][pInd]=f(sInd-1,pInd-1,s,p,dp);
        }
        if(p[pInd-1]=='*'){
            return dp[sInd][pInd]=(f(sInd,pInd-1,s,p,dp) ||
            f(sInd-1,pInd,s,p,dp));
        }
        return dp[sInd][pInd]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        
        dp[0][0]=true;
        for(int i=1;i<=s.size();i++){
            dp[i][0]=false;
        }
        for(int i=1;i<=p.size();i++){
            bool flag=true;
            for(int j=1;j<=i;j++){
                if(p[j-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][i]=flag;
        }
        
        for(int sInd=1;sInd<=s.size();sInd++){
            for(int pInd=1;pInd<=p.size();pInd++){
                if(s[sInd-1]==p[pInd-1] || p[pInd-1]=='?'){
                dp[sInd][pInd]=dp[sInd-1][pInd-1];
                }
                else if(p[pInd-1]=='*'){
                    dp[sInd][pInd]=(dp[sInd][pInd-1] || dp[sInd-1][pInd]);
                }
                else dp[sInd][pInd]=false;
            }
        }
        return dp[s.size()][p.size()];
        
    }
};