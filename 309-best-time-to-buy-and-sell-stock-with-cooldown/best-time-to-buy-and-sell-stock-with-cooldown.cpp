class Solution {
public:

    int maxdp(int day ,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(day >= prices.size()) return 0 ;

        int profit = 0 ;
        if(dp[day][buy] != -1) return dp[day][buy];
        if(buy){
            profit = max(-prices[day] + maxdp(day+1,0,prices,dp),
                            0+maxdp(day+1,1,prices,dp));
        }

        else{
            profit = max(prices[day] + maxdp(day+2,1,prices,dp),
                            0+maxdp(day+1,0, prices,dp));
        }

        return dp[day][buy] = profit ;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        //return maxdp(0,1,prices,dp);
        for(int day = n-1 ; day >=0 ; day--){
        for(int buy = 0 ; buy <=1 ; buy++){
            int profit = 0 ;
            
            if(buy){
                profit = max(-prices[day] +dp[day+1][0],
                                0+dp[day+1][1]);
            }

            else{
                profit = max(prices[day] + dp[day+2][1],
                                0+dp[day+1][0]);
            }

            dp[day][buy] = profit ;
        }
        }

        return dp[0][1];
    }
};