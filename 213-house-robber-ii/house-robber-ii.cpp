class Solution {
public:

    int robdp(vector<int> &nums,int ind , vector<int>&dp){
        if(ind ==0) return nums[0];
        if(ind == 1) return max(nums[0],nums[1]);

        if(dp[ind] != -1) return dp[ind];
        int left = nums[ind] + robdp(nums,ind-2,dp);
        int right = robdp(nums,ind-1,dp);

        return dp[ind] = max(left,right);
    }
    int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n, 0); // Updated initialization
    vector<int> dp2(n, 0); // Correctly initialize dp2

    // First case: Consider houses from 0 to n-2
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int ind = 2; ind < n; ind++) {
        int left = nums[ind] + dp[ind-2];
        int right = dp[ind-1];
        dp[ind] = max(left, right);
    }
    int left = dp[n-2]; // Max amount robbed from 0 to n-2

    // Second case: Consider houses from 1 to n-1
    nums[0] = 0; // Update nums[0] to 0 for the second case
    dp2[0] = nums[0];
    dp2[1] = max(nums[0], nums[1]);
    for (int ind = 2; ind < n; ind++) {
        int left = nums[ind] + dp2[ind-2];
        int right = dp2[ind-1];
        dp2[ind] = max(left, right);
    }
    int right = dp2[n-1]; // Max amount robbed from 1 to n-1

    return max(left, right);
}

};