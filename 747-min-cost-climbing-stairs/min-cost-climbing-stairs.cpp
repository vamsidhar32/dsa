class Solution {
public:
    int costdp(vector<int>&cost,int ind , vector<int>&dp){
        if(ind == 0 || ind == 1) return cost[ind];
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = cost[ind] + min(costdp(cost,ind-1,dp),costdp(cost,ind-2,dp)); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();
        vector<int>dp(n,-1);

        return min(costdp(cost, n-1,dp) , costdp(cost,n-2,dp));
    }
};