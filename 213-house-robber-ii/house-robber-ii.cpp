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
        if(n==0) return 0 ;
        if(n==1) return nums[0];

        vector<int>dp(n+1,-1);

        int left = robdp(nums,n-2,dp);

        nums[0] = 0 ;
        vector<int>dp2(n+1,-1);
        int right = robdp(nums,n-1,dp2);

        cout<< left <<" " << right ;

        return max(right,left);

        
    }
};