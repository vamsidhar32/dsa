class Solution {
public:

    void dfs(int i , int j , vector<vector<char>>&grid,vector<int> &delrow,vector<int>&delcol){
        grid[i][j] = 'v' ;
        int n = grid.size();
        int m = grid[0].size();
        for(int k = 0 ; k <4 ; k++){
            int newrow = i+delrow[k];
            int newcol = j+delcol[k];
            if(newrow >=0 && newcol >=0 && newrow <n && newcol <m){
            if(grid[newrow][newcol] == 'O'){
                dfs(newrow,newcol,grid,delrow,delcol);
            }
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        //vector<vector<char>>grid = board;
        int n = board.size();
        int m = board[0].size();
        vector<int>delrow{0,0,-1,1};
        vector<int>delcol{-1,1,0,0};
        for(int i = 0 ; i < m; i++){
            if(board[0][i] == 'O'){
                dfs(0,i,board,delrow,delcol);
            }
            if(board[n-1][i] == 'O'){
                dfs(n-1,i,board,delrow,delcol);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O'){
                dfs(i,0,board,delrow,delcol);
            }
            if(board[i][m-1] == 'O'){
                dfs(i,m-1,board,delrow,delcol);
            }
        }


        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <m ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'v'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};