class Solution {
public:
    void fliprow(int i , vector<vector<int>>&grid){
        int n = grid[0].size();
        for(int j = 0 ; j <n ; j++){
            grid[i][j] = grid[i][j] ^ 1;
        }

    }
    bool countzeroes(int j , vector<vector<int>>&grid){
        int count = 0 ;
        int m = grid.size();
        for(int i =0 ; i<m ; i++){
            if(grid[i][j] == 0) count++;
        }

        if(count >m/2) return true;
        return false ;
    }
    void flipcolumn(int j , vector<vector<int>>&grid){
        int m = grid.size();
        for(int i = 0 ; i < m ; i++){
            grid[i][j] = grid[i][j]^1;
        }
    }

    int value(int i , vector<vector<int>>&grid){
        int n = grid[0].size();
        int ans = 0 ;
        for(int j = 0 ; j <n ;j++){
            if(grid[i][j] == 1) ans = ans + (1 << (n-j-1));
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i <m ; i++){
            if(grid[i][0] == 0){
                fliprow(i,grid);
            }
        }
        for(int j = 1 ; j<n; j++){
            if(countzeroes(j,grid)){
                flipcolumn(j,grid);
            }
        }

        int ans = 0 ; 
        for(int i = 0 ; i <m ; i++){
            ans = ans +value(i,grid);
        }

        return ans ;
    }
};