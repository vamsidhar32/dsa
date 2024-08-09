class Solution {
public:

    int mindp(int i , int j , int n , int  m ,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if( i == n-1 && j == m-1) return grid[n-1][m-1];

        if(dp[i][j] != -1) return dp[i][j];
        int down = INT_MAX;
        if(i+1 <n ) down = grid[i][j] + mindp(i+1,j,n,m,grid,dp);
        int right = INT_MAX;
        if(j+1 < m) right = grid[i][j] + mindp(i,j+1,n,m,grid,dp);

        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if( n == 0) return -1 ;
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return mindp(0,0,n,m,grid,dp);
    }
};