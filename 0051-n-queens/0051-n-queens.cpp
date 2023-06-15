class Solution {
public:
    
    bool sol(int row, int col,vector<string>& board,int n){
        int tempR=row,tempC=col;
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=tempR;
        col=tempC;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        row=tempR;
        col=tempC;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        return true;
    }
    public:
    void findS(int n,int col, vector<string>& board,vector<vector<string>>& ans){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(sol(i,col,board,n)){
                board[i][col]='Q';
                findS(n,col+1,board,ans);
                board[i][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        findS(n,0,board,ans);
        return ans;
    }
};