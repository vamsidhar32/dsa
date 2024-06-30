class Solution {
public:

    int mindp(int i , int j , string s1 , string s2, vector<vector<int>>&dp){
        

        if(i <0) return j+1;
        if(j<0) return i+1;
        if(s1[i] == s2[j]){
            return mindp(i-1,j-1,s1,s2,dp);
        }
        else{
            return 1+ min(mindp(i-1,j,s1,s2,dp),mindp(i,j-1,s1,s2,dp));
        }
    }

    int minInsertions(string s) {
        string s1 = s ;
        reverse(s.begin(),s.end());
        string s2 = s ;
        int n = s.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //return mindp(n-1,n-1,s1,s2,dp);

        for(int i = 1 ; i<= n ; i++){
            for(int j = 1 ; j <=n ; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];

                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }


        return n - dp[n][n];
    }
};