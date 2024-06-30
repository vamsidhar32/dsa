class Solution {
public:
    int mindp(int i , int j , string word1, string word2, vector<vector<int>>&dp){
        

        if(j <0) return i+1;
        if(i <0) return j+1;

        if(dp[i][j] !=  -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = mindp(i-1,j-1,word1,word2,dp);
       
        else{
            //insert
            return dp[i][j] = min(1+mindp(i,j-1,word1,word2,dp),
                            min(1+mindp(i-1,j,word1,word2,dp),
                                   1+mindp(i-1,j-1,word1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        //return mindp(n-1,m-1,word1,word2,dp);
        vector<int>prev(m+1,-1);
        vector<int>curr(m+1,-1);
        // for(int i = 0 ; i <= n ; i++){
        //     dp[i][0] = i ;
        // }
        for(int j = 0 ; j <=m ; j++){
            prev[j] = j ;
        }

        for(int i = 1 ;i <=n ; i++){
            curr[0] = i ;

            for(int j = 1 ; j <=m ; j++){
                if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
       
                else{
                    //insert
                     curr[j] = min(1+curr[j-1],
                            min(1+prev[j],
                                   1+prev[j-1]));
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};