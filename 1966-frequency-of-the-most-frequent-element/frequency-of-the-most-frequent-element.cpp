class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        if(n == 1) return 1 ;
        int i =0 ; 
        int j =1 ; 
        int ans = 1 ;
        long long a = k ;

        while( j < n){
            a -= (long long)(nums[j] - nums[j-1]) * (long long)(j-i) ;

            if(a >= 0){
                ans = max(ans, j-i+1);
                j++;
            }

            else if(a < 0){
                while(a < 0){
                    a = a + nums[j]-nums[i];
                    i++ ;
                }
                j++; 
            }
        }

        return ans ;
    }
};