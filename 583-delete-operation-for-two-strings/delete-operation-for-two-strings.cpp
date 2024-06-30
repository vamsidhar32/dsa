class Solution {
public:

    int mindp(int i , int j , string s1 , string s2, vector<vector<int>>&dp){


        if(i <0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = mindp(i-1,j-1,s1,s2,dp);
        
        else{
            return dp[i][j] = 1+min(mindp(i-1,j,s1,s2,dp),mindp(i,j-1,s1,s2,dp));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return mindp(n-1,m-1,word1,word2,dp);
        for(int i = 1 ; i <=n ; i++){
            for(int j = 1; j <=m ; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];

                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return (n+m) - (2*dp[n][m]);
    }
};