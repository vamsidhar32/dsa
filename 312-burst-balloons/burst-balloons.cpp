class Solution {
public:

    int mcmdp(int i , int j , vector<int>&nums,vector<vector<int>>&dp){
        if( i >j) return 0;
        if(i == j) return nums[i-1]*nums[i]*nums[i+1];
        

        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int k = i ; k <= j ; k++){

            int tempans = nums[i-1]*nums[k]*nums[j+1] + mcmdp(i,k-1,nums,dp) + mcmdp(k+1,j,nums,dp);

            ans = max(ans,tempans);

        }

        return dp[i][j] = ans ;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);


        
        int n = nums.size(); 
        vector<vector<int>>dp (n,vector<int>(n,-1));
        return mcmdp(1,n-2,nums,dp);
    }
};