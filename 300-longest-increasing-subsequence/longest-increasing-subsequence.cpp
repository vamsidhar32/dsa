class Solution {
public:
    int lengthdp(int ind ,int prev , vector<int>&nums,vector<vector<int>>&dp){
        
        if(ind == nums.size()) return 0 ;

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int take = 0;
        if(prev == -1 || nums[prev] < nums[ind]){

            take = 1+ lengthdp(ind+1,ind,nums,dp);
            
        }

        int nottake = lengthdp(ind+1,prev,nums,dp);


        return dp[ind][prev+1] = max(take,nottake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return lengthdp(0,-1,nums,dp);
    }
};