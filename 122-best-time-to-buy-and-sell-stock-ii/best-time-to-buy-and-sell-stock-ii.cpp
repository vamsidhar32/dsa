class Solution {
public:
    int maxdp(int day, int buy ,vector<int>&prices,vector<vector<int>>&dp){
        

        if(day == prices.size()) return 0 ;
        if(dp[day][buy] != -1) return dp[day][buy];
        int profit = 0 ;

        if(buy == 1){
            profit = max(-prices[day] + maxdp(day+1,0,prices,dp),
                                0 + maxdp(day+1,1,prices,dp));
        }

        else{   
            profit = max(prices[day] + maxdp(day+1,1,prices,dp),
                                0 + maxdp(day+1,0,prices,dp));
        }

        return dp[day][buy] = profit ;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if (n==1) return 0 ;
        
        

        // int ans = 0 ;
        // int last = prices[0] ;
        // int top = prices[0] ;
        // int flag = 1 ;
        // for(int i = 1 ; i <prices.size();i++){
        //     if(prices[i] > prices[i-1]){
        //         top = prices[i];
        //         flag = 1;
        //         continue;
        //     }
        //     else{
        //         if(flag == 1){
        //             ans = ans + top-last;
        //             cout << top << " " << last <<endl ;
        //             flag = 0 ;
        //         }
        //         last = prices[i];
        //     }

        // }
        // if(top == prices[n-1]){
        //     ans = ans+ top-last ;
        // }

        // return ans ;

        //return maxdp(0, 1 ,prices,dp);
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        for(int i = 0 ;i <2 ;i++){
            dp[n][i] = 0 ;
        }

        for(int day = n-1; day >=0 ; day--){
            for(int buy = 0 ; buy <=1 ; buy++){
            int profit = 0 ;

            if(buy == 1){
                profit = max(-prices[day] +dp[day+1][0],
                                0 + dp[day+1][1]);
                }

            else{   
                profit = max(prices[day] + dp[day+1][1],
                                0 + dp[day+1][0]);
            }
            dp[day][buy] = profit;
            }
        }

        return dp[0][1];

    }
};