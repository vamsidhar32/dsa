class Solution {
public:

    bool find(int ind ,int sum , vector<int>nums,vector<vector<int>>&dp){
        
        if(sum == 0 ) return dp[ind][sum] = true;
        if(ind == nums.size()) return false ;

        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        

        
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
        

        for(int i = 0 ; i <= n ;i++){
            dp[i][0] = true ;
        }

        for(int i = 1 ; i <=sum ;i++){
            dp[n][i] = false ;
        }

        for(int i = n-1 ; i >=0 ; i--){
            for(int j = 1 ; j <=sum ;j++){
                bool take = false ;
                if( j- nums[i] >=0) take = dp[i+1][j-nums[i]];
                bool nottake = dp[i+1][j];

                dp[i][j] = take||nottake;
            }
        }

        return dp[0][sum];
    }
};