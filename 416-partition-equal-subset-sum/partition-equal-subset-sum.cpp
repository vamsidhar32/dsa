class Solution {
public:


    bool isdp(int ind , int sum , vector<int> &nums, vector<vector<int>>& dp){

        if(sum == 0) return true ;
        if(ind == 0){
            if(nums[ind] == sum) return true ;
            else return false ;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool take = false ;
        if(sum - nums[ind] >=0) take = isdp(ind-1,sum - nums[ind] , nums,dp);
        if(take) return dp[ind][sum] = true ;

        bool nottake = isdp(ind-1,sum,nums,dp);
        if(nottake) return dp[ind][sum] = true ;

        return dp[ind][sum] = false ;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum %2 == 1) return false;
        sum = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return isdp(n-1,sum,nums,dp);
    }
};