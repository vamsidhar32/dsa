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
        if(n ==0 ) return 0 ;
        if(n == 1) return nums[0];
        vector<int>dp(n+1,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i = 2 ; i <n ; i++){
            int left = nums[i] + dp[i-2];
            int right = dp[i-1];

            dp[i] = max(left,right);
        }

        return dp[n-1];
    }
};