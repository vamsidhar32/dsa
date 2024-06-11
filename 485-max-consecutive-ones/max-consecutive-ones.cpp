class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans ;
        int maxx = 0 ;
        int j = 0 ; 
        for(int i =0 ; i <nums.size() ; i++){
            if(nums[i] == 1) j++;
            else{
                maxx = max(maxx,j);
                j = 0 ; 
            }
        }
        maxx = max(maxx,j);

        return maxx;
    }
};