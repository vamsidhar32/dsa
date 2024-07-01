class Solution {
public:

    bool compare(int i , int j ){
        return i % j == 0 || j % i == 0 ;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int index = -1 ;

        int ans = -1 ;
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = 0  ; j < i ; j++){
                if(compare(nums[i],nums[j]) && dp[j] +1 > dp[i]){
                    dp[i] = dp[j]+1 ;
                    parent[i] = j ;
                }
            }


            if(dp[i] > ans ){
                ans = dp[i] ;
                index = i ;
            }
        }

        vector<int>temp ;
        while(parent[index] != -1){
            temp.push_back(nums[index]);
            index = parent[index] ;
        }
        temp.push_back(nums[index]);

        reverse(temp.begin(),temp.end());

        return temp ;
    }
};