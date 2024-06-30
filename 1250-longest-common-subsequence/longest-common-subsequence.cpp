class Solution {
public:

    int longdp(int i ,int j , string &text1,string &text2, vector<vector<int>>&dp){

        if(i == 0 || j == 0) return 0 ;

        if(dp[i][j] != -1 ) return dp[i][j];
        if(text1[i-1] == text2[j-1] ){
            return 1 + longdp(i-1,j-1,text1,text2,dp);
        }

        else {
            return dp[i][j] = max(longdp(i-1,j,text1,text2,dp), longdp(i,j-1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return longdp(n,m,text1,text2,dp);
    }
};