class Solution {
public:

    int minidp(int i , int j , vector<vector<int>>&dp,int n,vector<vector<int>>&triangle){
        if(i == n-1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];

        int left = INT_MAX ;
        if(i<n-1) left = triangle[i][j] + minidp(i+1,j,dp,n,triangle);

        int right = INT_MAX;
        if(i<n-1) right = triangle[i][j] +minidp(i+1,j+1,dp,n,triangle);


        return dp[i][j] = min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return minidp(0,0,dp,n,triangle);
    }
};