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
        
        //return climbdp(n,dp);
        for(int ind = 1 ; ind <= n ; ind++){
            if(ind == 1){
                dp[ind] = 1 ;
                continue ;
            }
            if(ind == 2) {
                dp[ind] = 2 ;
                continue ;
            }
            //if(dp[ind] != -1) return dp[ind];

            int left = dp[ind-1];
            int right =dp[ind-2];

            dp[ind] = left+ right ;
        }

        return dp[n];
    }
};