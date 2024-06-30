class Solution {
public:

    bool isdp(int i , int j , string p  , string s , vector<vector<int>>&dp){
        
        if(i<0 && j <0) return true ;
        if(i<0 && j >=0) return false ;
        if(j<0){
            for(int j = 0 ; j <= i ; j++){
                if(p[j] != '*') return false ;
            }
            return true ;
        }

        if(dp[i][j] != -1) return dp[i][j] ;

        if(p[i] == s[j]) return dp[i][j] = isdp(i-1,j-1,p,s,dp); 
        else if(p[i] == '?') return dp[i][j] = isdp(i-1,j-1,p,s,dp);
        else if(p[i] == '*'){
            return dp[i][j]  = isdp(i-1,j,p,s,dp) || isdp(i,j-1,p,s,dp);
        }
        else return false ;
        
    }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return isdp(n-1,m-1,p,s,dp);
        dp[0][0] = 1 ;
        for(int j =1 ; j <=m; j++){
            dp[0][j] = 0 ;
        }
        for(int i = 1 ; i <= n ; i++){
            bool allStars = true; // Comment: Introduce a flag to check if all previous characters are '*'
            for(int k = 0 ; k < i ; k++){ // Comment: Corrected the loop range from k = 0 to k < i
                if(p[k] != '*') { // Comment: Fixed p[k] instead of p[k-1]
                    allStars = false; // Comment: Reset flag if non-star character found
                    break; // Comment: Exit loop early since we found a non-star character
                }
            }
            if(allStars) dp[i][0] = 1 ; // Comment: Set dp[i][0] to 1 if all previous characters are '*'
            else dp[i][0] = 0; // Comment: Otherwise, set dp[i][0] to 0
        }


        for(int i = 1 ; i <=n ; i++){
            for(int j = 1 ; j <=m; j++){
                if(p[i-1] == s[j-1])  dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '?')  dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*'){
                    dp[i][j]  = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j] = 0 ;
            }
        }

        return dp[n][m];
    }
};