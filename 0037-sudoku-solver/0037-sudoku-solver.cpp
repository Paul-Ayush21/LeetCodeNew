class Solution {
public:
    
    bool check(vector<vector<char>> &board,int row,int col, char k){
        
        int r1= row-row%3,c1=col-col%3;
        // int r2=row-r1,c2=col-c1;
        for( int x=0;x<9;x++) if(board[x][col]==k) return false;
        for( int x=0;x<9;x++) if(board[row][x]==k) return false;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[r1+i][c1+j]==k)return false;
            }
        }
        return true;
        
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(check(board,i, j, k)){
                            cout<<"1";
                            board[i][j]=k;
                            if(solve(board)){
                                cout<<"2";
                                return true;
                            }
                            else{
                                cout<<"3";
                                board[i][j]='.';
                            }
                            
                        }
                    }
                    return false;
                }   
            
            }
            
        }
        cout<<"5";
        return true;
    }
        
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};