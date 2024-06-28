class Solution {
public:
    int climbStairss(int n,vector<int>&dp) {
        if(n == 1) return 1 ;
        if(n == 2 ) return 2 ;

        if(dp[n] != -1) return dp[n] ;
        int leftcount = climbStairss(n-1,dp);
        int rightcount = climbStairss(n-2,dp);


        return dp[n] = leftcount +rightcount;
    }
    int climbStairs(int n ){
        vector<int>dp(n+1,-1);

        return climbStairss(n,dp);
    }
};