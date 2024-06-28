class Solution {
public:

    int rob (vector<int>&nums,int ind ,vector<int>&dp){
        if(ind == 0 ) return nums[0];
        if(ind == 1) return max(nums[0],nums[1]);

        if(dp[ind] != -1){
            return dp[ind];
        }

        int left = nums[ind] + rob(nums,ind-2,dp);

        int right = rob(nums,ind-1,dp);

        return dp[ind] = max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);

        return rob(nums,n-1,dp);
    }
};