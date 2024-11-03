class Solution {
public:

    int fibdp(int i , vector<int> &dp){
        if(i == 0 || i == 1) return i;
        if(dp[i] != -1) return dp[i];
        return dp[i] = fibdp(i-1,dp) + fibdp(i-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        //return fibdp(n,dp);
        int prev = 0 ;
        int curr = 1 ;
        for(int i = 0 ; i<=n ; i++){
            if(i == 0 || i == 1){
                dp[i] = i;
                continue ;
            } 
            //if(dp[i] != -1) return dp[i];
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n] ;
    }
};