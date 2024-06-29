class Solution {
public:

    int finddp(int ind ,int T ,vector<int>&nums,vector<vector<int>>&dp){
        
        if(ind == 0){
            int k = 0 ;
            if(T == nums[0]) k++ ; //takecase ;
            if(T == 0)  k++ ; //nottakecase;
            return k ;

        }
        if(dp[ind][T] != -1) return dp[ind][T];
        int take = 0;
        if(nums[ind] <= T) take = finddp(ind-1,T-nums[ind] , nums,dp);

        int nottake = finddp(ind-1,T,nums,dp);

        return dp[ind][T] = take +nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int totalsum = accumulate(nums.begin(),nums.end(),0);

        if((totalsum+target)% 2 == 1) return 0 ;
        if(abs(target) > totalsum) return 0 ;
        int T = (target+totalsum)/2;

        vector<vector<int>>dp(n,vector<int>(T+1,-1));
        return finddp(n-1,T,nums,dp);
    }
};