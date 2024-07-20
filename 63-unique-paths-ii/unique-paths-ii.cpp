class Solution {
public:

    int pathdp(int i , int j ,vector<vector<int>> &obstacleGrid, int m ,int n ,vector<vector<int>>&dp){
        if(obstacleGrid[i][j] == 1) return 0 ;
        else if(i == n-1 && j == m-1 ) return 1 ;
        if(dp[i][j] != -1) return dp[i][j];
        int left = 0 ;
        if(i+1 < n) left = pathdp(i+1,j,obstacleGrid,m,n,dp);

        int right = 0 ;
        if(j+1 <m) right = pathdp(i,j+1,obstacleGrid,m,n,dp);

        return dp[i][j] = left+right ;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        if(n == 0) return -1 ;
        int m = obstacleGrid[0].size();

        //vector<vector<int>>dp(n,vector<int>(m,-1));
        //return pathdp(0 , 0 , obstacleGrid,m,n,dp);
        vector<long long >prev(m,1);
        vector<long long >curr(m,1);

        for(int i = n-1 ; i >=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                if(obstacleGrid[i][j] == 1) {curr[j] = 0 ; continue;}
                else if(i == n-1 && j == m-1 ) {curr[j] = 1 ; continue ;}
                //if(dp[i][j] != -1) return dp[i][j];
                long long int left = 0 ;
                if(i+1 < n) left = prev[j];

                long long int right = 0 ;
                if(j+1 <m) right = curr[j+1];

                curr[j] = left+right ;
                        
            }
            prev = curr;
        }

        return prev[0];
    }
};