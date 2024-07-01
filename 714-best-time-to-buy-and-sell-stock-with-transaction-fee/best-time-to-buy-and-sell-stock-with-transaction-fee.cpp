class Solution {
public:


    int maxdp(int day ,int buy, vector<int>&prices,vector<vector<int>>&dp ,int fee){
        if(day == prices.size()) return 0 ;

        int profit = 0 ;
        if(dp[day][buy] != -1) return dp[day][buy];
        if(buy){
            profit = max(-prices[day]+ maxdp(day+1,0,prices,dp,fee),
                            0+ maxdp(day+1,1,prices,dp,fee));

        }
        else{
            profit = max(prices[day]+ maxdp(day+1 , 1, prices,dp,fee) - fee ,
                            0+maxdp(day+1,0,prices,dp,fee));
        }

        return dp[day][buy] = profit ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        return maxdp(0,1,prices,dp,fee);
    }
};