class Solution {
public:
    #define mod 1000000007


    int helpdp(int index , string s , int k,vector<int>&dp){
        if(index == s.size()){
            return 1 ;
        }

        if(dp[index] != -1) return dp[index];

        int ways = 0 ;
        long long num = 0 ;
        num = s[index] - '0';
        if(num == 0) return 0 ;


        for(int i = index+1 ; i<=s.size();i++){
            if(num >k) break;
            ways  = ways + helpdp(i,s,k,dp);
            ways = ways%mod ;
            if(i != s.size()) num = num*10 + s[i] - '0' ;    
        }

        return dp[index] = ways; 
    }




    int numberOfArrays(string s, int k) {
        int n = s.size();

        vector<int>dp(n+1,1);
        //return helpdp(0,s,k,dp);

        for(int index = n-1 ; index >=0 ; index--){
            int ways = 0 ;
            long long num = 0 ;
            num = s[index] - '0';
            if(num == 0) {
                dp[index] = 0 ;
                continue ;
            }


            for(int i = index+1 ; i<=s.size();i++){
                if(num >k) break;
                ways  = ways + dp[i];
                ways = ways%mod ;
                if(i != s.size()) num = num*10 + s[i] - '0' ;    
            }

            dp[index] = ways; 
        }

        return dp[0];
    }
};