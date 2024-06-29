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
        int sum = (target+totalsum)/2;

        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        //return finddp(n-1,sum,nums,dp);

        vector<int>prev(sum+1,-1);
        vector<int>curr(sum+1,-1);
        for(int T= 0 ; T<= sum ;T++){
            int k = 0;
            if(T == nums[0]) k++ ; //takecase ;
            if(T == 0)  k++ ; //nottakecase;
            prev[T] = k ;
            
        }

        for(int ind = 1 ; ind <n; ind++){
            for(int T = 0 ; T<=sum; T++){
                
                int take = 0;
                if(nums[ind] <= T) take = prev[T-nums[ind]];

                int nottake = prev[T];

                curr[T] = take +nottake;
            }
            prev = curr;
        }

        return prev[sum];

    }
};