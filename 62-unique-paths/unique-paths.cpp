class Solution {
public:

    int uniquedp(int i , int j , int m , int n , vector<vector<int>>&dp){

        if( i == m-1 && j == n-1) return 1 ;

        if(dp[i][j] != -1) return dp[i][j];
        int left = 0 ; 
        if(i+1 < m) left = uniquedp(i+1,j,m,n,dp);

        int right = 0 ;
        if(j+1 <n) right = uniquedp(i,j+1,m,n,dp);

        return dp[i][j] = left+right ;
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp (m+1,vector<int>(n+1,-1));


        vector<int>prev(n+1,-1);
        vector<int>curr(n+1,-1);
        //return uniquedp(0,0,m,n,dp);

        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                if( i == m-1 && j == n-1) {dp[i][j] = 1 ; continue ;}

                //if(dp[i][j] != -1) return dp[i][j];
                int left = 0 ; 
                if(i+1 < m) left = prev[j];

                int right = 0 ;
                if(j+1 <n) right = curr[j+1];

                curr[j] = left+right ;
            }
            prev = curr ;
        }

        return -prev[0];
    }
};