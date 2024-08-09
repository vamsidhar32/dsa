class Solution {
public:

    int mindp(int i , int j , int n , vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if( i == n-1) return triangle[i][j];


        if(dp[i][j] != -1) return dp[i][j];
        //int left = INT_MAX;
        int left = triangle[i][j] + mindp(i+1,j,n,triangle,dp);
        //int right = INT_MAX;
        int right = triangle[i][j] + mindp(i+1,j+1,n,triangle,dp);


        return dp[i][j] = min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return mindp(0,0,n,triangle,dp);

        for(int i = n-1 ; i >=0  ; i--){
            for(int j = m-1 ; j>=0 ; j-- ){
                if( i == n-1) dp[i][j] = triangle[i][j];


                //if(dp[i][j] != -1) return dp[i][j];
                int left = INT_MAX;
                if(i+1 <= n-1) left = triangle[i][j] + dp[i+1][j];
                int right = INT_MAX;
                if(i+1 <= n-1) right = triangle[i][j] + dp[i+1][j+1];


                dp[i][j] = min(left,right);
            }
        }
        return dp[0][0];
    }
};