class Solution {
public:

    int longdp(int i ,int j , string &text1,string &text2, vector<vector<int>>&dp){

        if(i < 0 || j <0) return 0 ;

        if(dp[i][j] != -1 ) return dp[i][j];
        if(text1[i] == text2[j] ){
            return 1 + longdp(i-1,j-1,text1,text2,dp);
        }

        else {
            return dp[i][j] = max(longdp(i-1,j,text1,text2,dp), longdp(i,j-1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m,-1));

        return longdp(n-1,m-1,text1,text2,dp);
    }
};