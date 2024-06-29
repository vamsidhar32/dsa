class Solution {
public:

    bool find(int ind ,int sum , vector<int>nums,vector<vector<int>>&dp){
        

        if(ind == nums.size()) return false ;

        if(dp[ind][sum] != -1) return dp[ind][sum];
        if(sum == 0 ) return dp[ind][sum] = true;
        

        
        bool take = false;
        if(sum-nums[ind] >=0) take = find(ind+1,sum-nums[ind],nums,dp);
        if(take) return dp[ind][sum] = true;

        
        bool nottake = find(ind+1,sum,nums,dp);
        if(nottake) return dp[ind][sum] = true ;

        return dp[ind][sum] = false ;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum %2 == 1) return false ;
        sum = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return find(0,sum,nums,dp);
    }
};