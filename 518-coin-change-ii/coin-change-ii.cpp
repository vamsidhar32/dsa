class Solution {
public:

    int changedp(int ind , int A , vector<int>&coins,vector<vector<int>>&dp){

        if(A == 0) return 1 ;
        if(ind ==0){
            //nottakecase;
            if(A % coins[ind] == 0) return 1 ;//takecase;
            else return 0 ;
        }

        if(dp[ind][A] != -1) return dp[ind][A];
        int take = 0 ;
        if(A >= coins[ind]) take = changedp(ind,A-coins[ind],coins,dp);
        int nottake = changedp(ind-1,A,coins,dp);


        return dp[ind][A] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return changedp(n-1,amount,coins,dp);
    }
};