class Solution {
public:

    int maxdp(int day,int buy,int tran,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(tran == 0) return 0 ;
        if(day == prices.size()) return 0 ;

        int profit = 0 ;

        if(dp[day][buy][tran] != -1) return dp[day][buy][tran] ;

        if(buy ==1){
            profit = max(-prices[day] + maxdp(day+1,0,tran,prices,dp),
                            0 + maxdp(day+1,1,tran,prices,dp));
        }
        else{
            profit = max(prices[day]+maxdp(day+1,1,tran-1,prices,dp),
                            0 + maxdp(day+1,0,tran,prices,dp));
        }

        return  dp[day][buy][tran] = profit ;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return maxdp(0,1,2,prices,dp);
    }
};