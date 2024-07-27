class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0 ;
        int start = 0 ;
        int startpoint = -1;
        int endpoint = -1; 
        int ans = INT_MIN;

        for(int i = 0 ; i < nums.size(); i++){
            sum = sum + nums[i];

            if(sum > ans){
                ans = sum ;
                startpoint = start;
                endpoint = i;
            }
            if(sum <0) {
                sum = 0 ;
                start = i+1 ;
            }
        }

        return ans ;
        
    }
};