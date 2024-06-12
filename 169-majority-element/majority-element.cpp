class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0 ) return -1 ;
        int count = 1 ; 
        int ele = nums[0];
        for(int i = 1; i <nums.size(); i++){
            if(count == 0) ele = nums[i] ;
            if(nums[i] == ele) count++;
            else count--;
        }

        return ele ;
    }
};