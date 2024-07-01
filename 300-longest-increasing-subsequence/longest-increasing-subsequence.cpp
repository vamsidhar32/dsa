class Solution {
public:
    int lengthdp(int ind ,int prev , vector<int>&nums,vector<vector<int>>&dp){
        
        if(ind == nums.size()) return 0 ;

        if(dp[ind][prev] != -1) return dp[ind][prev];
        int take = 0;
        if(prev == 0 || nums[prev-1] < nums[ind]){

            take = 1+ lengthdp(ind+1,ind+1,nums,dp);
            
        }

        int nottake = lengthdp(ind+1,prev,nums,dp);


        return dp[ind][prev] = max(take,nottake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //return lengthdp(0,0,nums,dp);


        for(int ind = n-1 ; ind >=0 ; ind--){
        for(int prev = 0 ; prev < n ; prev++){
            int take = 0;
            if(prev == 0 || nums[prev-1] < nums[ind]){

                take = 1+ dp[ind+1][ind+1];
            
            }

            int nottake = dp[ind+1][prev];


            dp[ind][prev] = max(take,nottake);
        }
        }

        return dp[0][0];
    }
};