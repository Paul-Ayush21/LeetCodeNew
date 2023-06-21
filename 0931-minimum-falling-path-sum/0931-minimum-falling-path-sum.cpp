class Solution {
public:
    int f(int r, int c,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(c<0||c>=matrix.size()){
            return 1e7;
        }
        if(r==0){
            return matrix[r][c];
        }
        
            if(dp[r][c]!=-1){return dp[r][c];}
            int down=matrix[r][c]+f(r-1,c,matrix,dp);
            int downLeft=matrix[r][c]+f(r-1,c-1,matrix,dp);
            int downRight=matrix[r][c]+f(r-1,c+1,matrix,dp);

            int k=min(down,downLeft);
            return dp[r][c]=min(k,downRight);
        
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=1e7;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // for(int i=0;i<matrix.size();i++){
        //     int k=f(n-1,i,matrix,dp);
        //     mini=min(mini,k);
        // }
        
        for(int i=0;i<matrix.size();i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int down =matrix[i][j];
                if(i-1<n){down+=dp[i-1][j];}
                else{down+=1e7;}
                int dL=matrix[i][j];
                if(i-1<n && j-1>=0){dL+=dp[i-1][j-1];}
                else{dL+=1e7;}
                int dR=matrix[i][j];
                if(i-1<n && j+1<n){dR+=dp[i-1][j+1];}
                else{dR+=1e7;}
                dp[i][j]= min(down,min(dL,dR));
            }
        }
        mini=dp[n-1][0];
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};