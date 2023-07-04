class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int i=str1.size(),j=str2.size();
        vector<vector<int>> dp(i+1,vector<int>(j+1,0));
        for(int k=0;k<=i;k++){
            dp[k][0]==0;
        }
        for(int k=0;k<=j;k++){
            dp[0][k]==0;
        }
        for(int x=1;x<=i;x++){
            for(int y=1;y<=j;y++){
                if(str1[x-1]==str2[y-1]){
                    dp[x][y]=1+dp[x-1][y-1];
                }
                else{
                    dp[x][y]=max(dp[x-1][y],dp[x][y-1]);
                }
            }
        }
        i=str1.size();
        j=str2.size();
        // cout<<dp[i][j];
        string k="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                k=str1[i-1]+k;
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    k=str1[i-1]+k;
                    i--;
                }
                else{
                    k=str2[j-1]+k;
                    j--;
                }
            }
        }
        while(i>0){
            k=str1[i-1]+k;
            i--;
        }
        while(j>0){
            k=str2[j-1]+k;
            j--;
        }
        
        return k;
    }
    
};