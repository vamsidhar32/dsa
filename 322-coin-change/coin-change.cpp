class Solution {
public:

    int coindp(int ind,vector<int>&coins,int amount ,vector<vector<int>>&dp){
        
        if(ind == 0){
            if(amount % coins[0] == 0) return amount/coins[0] ;
            else return 1e9;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];
        int nottake = coindp(ind-1,coins,amount,dp);

        int take = 1e9;
        if(coins[ind] <= amount) take = 1+ coindp(ind,coins,amount-coins[ind],dp);


        return dp[ind][amount] = min(take,nottake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0) return 0 ;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        if(coindp(n-1,coins,amount,dp) == 1e9) return -1;
        return coindp(n-1,coins,amount,dp);
    }
};