class Solution {
public:


    int unidp(int i , int j , int n , int m , vector<vector<int>> &obstacleGrid , vector<vector<int>> &dp){
        
        
        if(obstacleGrid[i][j] == 1) return 0 ;
        if( i == n-1 && j == m-1) return 1 ;

        if(dp[i][j] != -1) return dp[i][j];
        int left = 0 ;
        if(i+1 <= n-1) left = unidp(i+1,j,n,m,obstacleGrid,dp);

        int right = 0 ;
        if(j+1 <= m-1) right = unidp(i,j+1,n,m,obstacleGrid,dp);

        return dp[i][j] =  left + right ;
    } 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) return -1 ;
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return unidp(0,0,n,m,obstacleGrid,dp);
    }
};