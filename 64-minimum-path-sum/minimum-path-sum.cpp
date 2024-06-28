class Solution {
public:
    int minpathdp(int i , int j , vector<vector<int>>&grid,vector<vector<int>>&dp,int &m, int &n){
        if(i == n-1 && j == m-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int leftsum = INT_MAX ;
        if(i+1 < n) leftsum = grid[i][j] + minpathdp(i+1,j,grid,dp,m,n);

        int rightsum = INT_MAX ;
        if(j+1 < m) rightsum = grid[i][j] + minpathdp(i,j+1,grid,dp,m,n);

        return dp[i][j] = min(leftsum,rightsum);
    }
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return minpathdp(0,0,grid,dp,m,n);
    }
};