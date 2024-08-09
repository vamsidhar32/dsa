class Solution {
public:

    int minidp(int i , int j , vector<vector<int>> &matrix,vector<vector<int>>&dp,int n){
        if(i == n-1) return matrix[i][j];


        if(dp[i][j] != -1) return dp[i][j];

        int left = INT_MAX;
        if(i+1 < n && j-1 >=0) left = matrix[i][j]+ minidp(i+1,j-1,matrix,dp,n);

        int right = INT_MAX;
        if(i+1 <n && j+1 <n) right = matrix[i][j] + minidp(i+1,j+1,matrix,dp,n);

        int center = INT_MAX;
        if(i+1 <n)           center = matrix[i][j] +minidp(i+1,j,matrix,dp,n);

        return dp[i][j] = min(left,min(right,center));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>prev(n,-1);
        vector<int>curr(n,-1);

        for(int i = n-1 ; i >=0 ; i--){
            for(int j = 0 ; j <= n-1 ; j++){
                if(i == n-1) {curr[j] = matrix[i][j]; continue ;}


                //if(dp[i][j] != -1) return dp[i][j];

                int left = INT_MAX;
                if(i+1 < n && j-1 >=0) left = matrix[i][j]+ prev[j-1];

                int right = INT_MAX;
                if(i+1 <n && j+1 <n) right = matrix[i][j] + prev[j+1];

                int center = INT_MAX;
                if(i+1 <n)           center = matrix[i][j] + prev[j];

                curr[j] = min(left,min(right,center));
            }
            prev = curr ;
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ;i++){
            ans = min(ans,prev[i]);
        }
        return ans;
    }
};