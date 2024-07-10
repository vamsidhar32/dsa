class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1);
        vector<int>hash(n,-1);
        int ind = -1 ;
        int ans =  1;
        for(int i = 0 ; i <nums.size();i++){
            for(int j = 0 ; j < i ; j++){

                if(nums[j] < nums[i] && 1+dp[j] > dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j ;
                    
                    
                }
            }
            if(dp[i] > ans ){
                        ans = dp[i];
                        ind = i ;
                        //cout << ind << "*";
                    }
        }
        // int index = -1 ;

        // for(int i = 0 ; i <n ; i++){
        //     if(dp[i] == ans ){
        //         index = i ;
        //         cout<<index << " " ;
        //      }
        // }
        vector<int> temp;
        while (ind != -1) {
            temp.push_back(nums[ind]);
            ind = hash[ind];
        }

        for(int i = 0 ; i <temp.size(); i++){
            cout <<temp[i] <<" " ;
        }
        return ans ;
    }
};