class Solution {
public:


    int mcmdp(int i , int j , vector<int>&cuts,vector<vector<int>>&dp){

        if(i > j ) return 0 ;
        

        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;

        
        for(int k = i ; k <=j ; k++ ){

            
            int cost = cuts[j+1] - cuts[i-1] + mcmdp(i,k-1,cuts,dp) + mcmdp(k+1,j,cuts,dp);
            
    
            ans  = min(ans,cost);
        }


        return dp[i][j] = ans ;
    }
    int minCost(int n, vector<int>& cuts) {


        
        int c = cuts.size();

        vector<vector<int>> dp(c+1, vector<int>(c+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return mcmdp(1,c,cuts,dp);
    }
};