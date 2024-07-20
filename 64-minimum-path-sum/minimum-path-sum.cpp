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
        //vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<int>prev (m,1);
        vector<int>curr(m,1);

        for(int i =n-1 ; i>=0 ; i--){
            for(int j =m-1 ; j>=0 ; j--){


                if(i == n-1 && j == m-1){curr[j] = grid[i][j]; continue;}

                //if(dp[i][j] != -1) return dp[i][j];

                int leftsum = INT_MAX ;
                if(i+1 < n) leftsum = grid[i][j] + prev[j];

                int rightsum = INT_MAX ;
                if(j+1 < m) rightsum = grid[i][j] + curr[j+1];

                curr[j] = min(leftsum,rightsum);
                //dp[i][j] =  grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
            }
            prev = curr;
        }

        return prev[0];
    }
};