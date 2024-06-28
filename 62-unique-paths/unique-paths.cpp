class Solution {
public:

    int uniquedp(int i , int j ,int m , int n ,vector<vector<int>>&dp){
        if(i == m-1 && j == n-1 ){
            return 1 ;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int left = 0 ;
        if(i+1 <m) left = uniquedp(i+1,j,m,n,dp);

        int right = 0 ;
        if(j+1 <n) right = uniquedp(i,j+1,m,n,dp);

        return dp[i][j] = left+right ;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return uniquedp(0,0,m,n,dp);
    }
};