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

        int k = sum ;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        //return isdp(n-1,sum,nums,dp);

        for(int ind = 0 ; ind <= n-1 ; ind++){
            for(int sum = 0 ; sum <= k ; sum++){
                if(sum == 0){dp[ind][sum] = true ; continue ;}
                if(ind == 0){
                    if(nums[ind] == sum){ dp[ind][sum] = true ; continue ;}
                    else {dp[ind][sum] = false ; continue ;}
                }

                //if(dp[ind][sum] != -1) return dp[ind][sum];


                bool take = false ;
                if(sum - nums[ind] >=0) take = dp[ind-1][sum - nums[ind]];
                if(take){dp[ind][sum] = true ; continue ;}

                bool nottake = isdp(ind-1,sum,nums,dp);
                if(nottake) {dp[ind][sum] = true ; continue ;}

                dp[ind][sum] = false ;
            }
        }

        return dp[n-1][k];
    }
};