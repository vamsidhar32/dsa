class Solution {
public:

    int fibdp(int i , vector<int> &dp){
        if(i == 0 || i == 1) return i;
        if(dp[i] != -1) return dp[i];
        return dp[i] = fibdp(i-1,dp) + fibdp(i-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return fibdp(n,dp);
    }
};