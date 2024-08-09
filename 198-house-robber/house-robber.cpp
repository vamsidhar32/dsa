class Solution {
public:

    int robdp(int ind , vector<int> &nums , vector<int> &dp){
        
        if(ind == 0) return nums[0];
        if(ind == 1) return max(nums[1],nums[0]);


        if(dp[ind] != -1) return dp[ind] ;
        
        int left = nums[ind] + robdp(ind-2,nums,dp);
        int right = robdp(ind-1,nums,dp);

        return dp[ind] = max(left,right);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1,-1);

        return robdp(n-1,nums,dp);
    }
};