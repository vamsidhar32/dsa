class Solution {
public:

    int climbdp(int ind , vector<int> &dp){
        if(ind == 1) return 1 ;
        if(ind == 2) return 2 ;

        if(dp[ind] != -1) return dp[ind];
        
        int left = climbdp(ind-1,dp);
        int right = climbdp(ind-2,dp);

        return dp[ind] = left+ right ;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
        return climbdp(n,dp);
    }
};